//
// Created by ruslan on 20.01.23.
//

#include "arithmetic.h"

#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "comparison.h"
#include "s21_decimal.h"

int AddSubFunc(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  bool dec = 0;

  memset(result, 0, sizeof(s21_decimal));
  result->bits[3] = value_1.bits[3];
  for (char i = 0; i < 96; i++) {
    int sum = dec + BitGetter(&value_2, i) + BitGetter(&value_1, i);
    dec = sum / 2;
    BitSetter(result, i, sum % 2);
  }
  if (dec) {
    error = HUGE_VAL_;
  }
  return error;
}

int Add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error;
  bool overflow = false;
  unsigned save_mod = 0;
  s21_decimal mod = {};

  if ((error = AddSubFunc(value_1, value_2, result)) &&
      ScaleGetter(&value_1) > 0) {
    error = OK;
    overflow = true;

    div10(&value_1, &mod);
    save_mod += mod.bits[0];
    div10(&value_2, &mod);
    save_mod += mod.bits[0];
    ScaleSetter(&value_1, (char)(ScaleGetter(&value_1) - 1));
    ScaleSetter(&value_2, (char)(ScaleGetter(&value_2) - 1));
    AddSubFunc(value_1, value_2, result);
  }
  if (!error) {
    save_mod *= 100;
    save_mod += overflow ? abs(g_mod) : abs(g_mod) * 10;
    g_mod = 0;
    if (save_mod >= 1000) {
      AddSubFunc(*result, (s21_decimal){{1}}, result);
      save_mod -= 1000;
    }
    if (save_mod > 500 ||
        (save_mod == 500 &&
         !Div(*result, (s21_decimal){{10}}, &(s21_decimal){}, &mod) &&
         mod.bits[0] % 2)) {
      AddSubFunc(*result, (s21_decimal){{1}}, result);
    }
  }
  return error;
}

void SubSubFunc(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  bool dec = 0;
  char msb = MSB(value_1);

  memset(result, 0, sizeof(s21_decimal));
  result->bits[3] = value_1.bits[3];
  for (char i = 0; i <= msb; ++i) {
    bool l_bit = BitGetter(&value_1, i);
    bool r_bit = BitGetter(&value_2, i);

    if (0 + r_bit + dec > l_bit) {
      BitSetter(result, i, 2 + l_bit - r_bit - dec);
      dec = 1;
    } else {
      BitSetter(result, i, l_bit ^ (r_bit || dec));
      dec = 0;
    }
  }
}

int Sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  unsigned mod = 0;
  s21_decimal dig = {};

  SubSubFunc(value_1, value_2, result);
  mod = g_mod < 0 ? 100 + g_mod : g_mod;
  g_mod = 0;
  if (mod > 50 || (mod == 50 &&
                   !Div(*result, (s21_decimal){{10}}, &(s21_decimal){}, &dig) &&
                   dig.bits[0] % 2)) {
    AddSubFunc(*result, (s21_decimal){{1}}, result);
  }
  return error;
}

int mul10(s21_decimal *num) {
  int error = OK;
  s21_decimal num1, num2;

  error = BitShift(*num, 3, &num1);
  if (!error) {
    BitShift(*num, 1, &num2);
    error = AddSubFunc(num1, num2, &num1);
    if (!error) *num = num1;
  }
  return error;
}

void div10(s21_decimal *num, s21_decimal *mod) {
  s21_decimal divisor = {{10}};

  Div(*num, divisor, num, mod);
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  char scale = (char)(ScaleGetter(&value_1) + ScaleGetter(&value_2));
  ScaleSetter(&value_1, scale);
  BitSetter(&value_1, 127,
            (char)((BitGetter(&value_1, 127) + BitGetter(&value_2, 127)) % 2));

  memset(result, 0, sizeof(s21_decimal));
  if (!IsNull(value_1) && !IsNull(value_2)) {
    for (char i = 0; i <= MSB(value_2) && !error; ++i) {
      if (BitGetter(&value_2, i)) {
        s21_decimal tmp = value_1, mod = {}, factor = {{1}}, tmp_mod = {};
        int counter = 0;
        while ((error = BitShift(tmp, i, &tmp)) && scale - counter > 0) {
          counter++;
          mul10(&factor);
          Div(value_1, factor, &tmp, &mod);
          ScaleSetter(&mod, scale);
          s21_decimal factor2 = {{1}}, save = mod;
          int counter2 = 0;
          while (BitShift(mod, i, &mod)) {
            counter2++;
            char scale_mod = ScaleGetter(&save);
            mul10(&factor2);
            Div(save, factor2, &mod, &tmp_mod);
            ScaleSetter(&tmp_mod, scale_mod);
            ScaleSetter(&mod, (char)(scale_mod - counter2));
            BitShift(tmp_mod, i, &tmp_mod);
          }
          ScaleSetter(&tmp, (char)(scale - counter));
        }
        if (!error) {
          Alignment(&tmp_mod, result);

          Add(*result, tmp_mod, result);
          Alignment(&mod, result);
          error = Add(*result, mod, result);
          Alignment(result, &tmp);
          if (!error) error = Add(*result, tmp, result);
        }
      }
    }
    if (!error) {
      if (ScaleGetter(result) > 28) {
        RoundToScale(result, 28);
      }
      ClearZeros(result);
    }
  }
  if (error == HUGE_VAL_ && BitGetter(&value_1, 127)) error = SMALL_VAL;
  return error;
}

bool Checker(s21_decimal *value_1, const s21_decimal value_2, const char r_msb,
             char *shift, s21_decimal *result, s21_decimal *mod) {
  bool ret;
  s21_decimal tmp;

  while (*shift > 0 &&
         (MSB(*value_1) - r_msb < *shift ||
          (!BitShift(value_2, *shift, &tmp) && IsLess(*value_1, tmp)))) {
    BitShift(*result, 1, result);
    (*shift)--;
  }
  if (*shift <= 0) tmp = value_2;
  if (*shift <= 0 && IsLess(*value_1, tmp)) {
    *mod = *value_1;
    ScaleSetter(mod, 0);
    if (!*shift) BitShift(*result, 1, result);
    ret = false;
  } else {
    BitShift(*result, 1, result);
    BitSetter(result, 0, 1);
    Sub(*value_1, tmp, value_1);
    ret = true;
  }
  return ret;
}

int Div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
        s21_decimal *mod) {
  memset(result, 0, sizeof(s21_decimal));
  result->bits[3] = value_1.bits[3];
  char r_msb = MSB(value_2);
  char shift = (char)(MSB(value_1) - r_msb);

  while (Checker(&value_1, value_2, r_msb, &shift, result, mod)) {
    shift--;
  }
  return 0;
}

s21_decimal Abs(s21_decimal src) {
  BitSetter(&src, 127, 0);
  return src;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;

  RoundToScale(&value_1, 28);
  RoundToScale(&value_2, 28);
  Alignment(&value_1, &value_2);
  memset(result, 0, sizeof(s21_decimal));
  if (!((BitGetter(&value_1, 127) + BitGetter(&value_2, 127)) % 2)) {
    error = Add(value_1, value_2, result);
  } else {
    if (s21_is_less(Abs(value_1), Abs(value_2))) {
      error = Sub(value_2, value_1, result);
    } else {
      error = Sub(value_1, value_2, result);
    }
  }
  ClearZeros(result);
  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  s21_negate(value_2, &value_2);
  error = s21_add(value_1, value_2, result);
  return error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  s21_decimal save = value_1;

  memset(result, 0, sizeof(s21_decimal));
  if (IsNull(value_2)) {
    error = DIV_BY_ZERO;
  } else if (!IsNull(value_1)) {
    BitSetter(&value_1, 127,
              (BitGetter(&value_1, 127) + BitGetter(&value_2, 127)) % 2);
    char scale = (char)(ScaleGetter(&value_1) - ScaleGetter(&value_2));

    while (scale < 0 && !mul10(&value_1)) {
      scale++;
    }
    s21_decimal mod = {}, dig = {}, tmp_mod = {};
    ScaleSetter(&value_1, (char)(scale <= 0 ? 0 : scale));
    if (scale >= 0) {
      AddZeros(&value_1);
      scale = ScaleGetter(&value_1);
    }
    Div(value_1, value_2, result, &mod);
    bool stop = false;
    while (!stop && !error && (scale < 0 || (!IsNull(mod) && scale < 28))) {
      error = mul10(&mod);
      if (error) {
        error = OK;
        div10(&value_2, &tmp_mod);
      } else {
        error = mul10(result);
      }
      if (scale >= 0 && error) {
        div10(&mod, &(s21_decimal){});
        error = OK;
        stop = 1;
      } else if (!error) {
        s21_decimal tmp;
        Div(mod, value_2, &tmp, &mod);
        error = Add(*result, tmp, result);
        scale++;
      }
      ScaleSetter(result, scale);
    }
    if (!error) {
      s21_mul(mod, (s21_decimal){{100}}, &mod);
      Div(mod, value_2, &mod, &(s21_decimal){});
      if (mod.bits[0] > 50 ||
          (mod.bits[0] == 50 &&
           !Div(*result, (s21_decimal){{10}}, &(s21_decimal){}, &dig) &&
           dig.bits[0] % 2))
        error =
            s21_add(*result, (s21_decimal){{1, 0, 0, result->bits[3]}}, result);
      Div(save, (s21_decimal){{10}}, &(s21_decimal){}, &mod);
      if (!error && tmp_mod.bits[0] >= 5 && mod.bits[0] >= 5)
        Sub(*result, (s21_decimal){{1}}, result);
      ClearZeros(result);
    }
    if (error == HUGE_VAL_ && BitGetter(result, 127)) error = SMALL_VAL;
  }
  return error;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;

  memset(result, 0, sizeof(s21_decimal));

  if (IsNull(value_2)) {
    error = DIV_BY_ZERO;
  } else if (!IsNull(value_1)) {
    BitSetter(result, 127,
              (BitGetter(&value_1, 127) + BitGetter(&value_2, 127)) % 2);
    char save = ScaleGetter(&value_2), scale = ScaleGetter(&value_1);
    s21_decimal mod = {}, mod_sum = {};

    scale = (char)(scale - save);
    ScaleSetter(&mod_sum, (char)(scale > 0 ? scale : 0));
    for (char i = 0; i < scale; ++i) {
      Div(value_1, (s21_decimal){{10}}, &value_1, &mod);
      for (int j = 0; j < i; ++j) {
        mul10(&mod);
      }
      Add(mod_sum, mod, &mod_sum);
    }
    Div(value_1, value_2, &(s21_decimal){}, &mod);
    if (scale < 0) {
      for (char i = scale; i < 0; ++i) {
        mul10(&mod);
      }
      Div(mod, value_2, &(s21_decimal){}, &mod);
    }
    s21_add(mod_sum, mod, result);
    ScaleSetter(result, (char)(ScaleGetter(result) + save));
  }
  return error;
}