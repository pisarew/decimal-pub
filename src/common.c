#include "common.h"

#include <string.h>

#include "arithmetic.h"
#include "s21_decimal.h"

int g_mod = 0;

bool BitGetter(const void *byte, const char bit) {
  int shift = 1 << bit % 8;

  return (*((char *)byte + bit / 8) & shift) == shift;
}

void BitSetter(void *byte, const char bit, bool value) {
  int shift = 1 << bit % 8;
  byte = (char *)byte + bit / 8;

  *(char *)(byte) =
      (char)(value ? *(char *)byte | shift : *(char *)byte & ~shift);
}

char ScaleGetter(const void *byte) { return *((char *)byte + 14); }

void ScaleSetter(void *byte, const char scale) { *((char *)byte + 14) = scale; }

int BitShift(s21_decimal number, char shift, s21_decimal *result) {
  int error = OK;
  char msb = MSB(number);

  if (msb + shift > 95) {
    error = HUGE_VAL_;
  } else {
    memset(result, 0, sizeof(s21_decimal));
    result->bits[3] = number.bits[3];

    if (shift > 0) {
      for (char i = 0; i <= msb; ++i) {
        BitSetter(result, (char)(i + shift), BitGetter(&number, i));
      }
    } else if (shift < 0) {
      for (char i = (char)(msb + shift); i >= 0; --i) {
        BitSetter(result, i, BitGetter(&number, (char)(i - shift)));
      }
    } else {
      *result = number;
    }
  }
  return error;
}

char MSB(s21_decimal number) {
  char ret = 95;

  for (char i = 95; !BitGetter(&number, i) && i >= 0; ret = --i)
    ;
  return ret;
}

void ClearZeros(s21_decimal *num) {
  s21_decimal tmp, mod;
  char scale;

  if (memcmp(num, (unsigned[3]){}, sizeof(int[3])) == 0) {
    num->bits[3] = 0;
  }
  while ((scale = ScaleGetter(num)) > 0 &&
         !Div(*num, (s21_decimal){{10, 0, 0, 0}}, &tmp, &mod) && !mod.bits[0]) {
    *num = tmp;
    ScaleSetter(num, --scale);
  }
}

void AddZeros(s21_decimal *num) {
  while (ScaleGetter(num) < 28 && !mul10(num)) {
    ScaleSetter(num, (char)(ScaleGetter(num) + 1));
  }
}

int Alignment(s21_decimal *lv, s21_decimal *rv) {
  s21_decimal *low, *high;
  ClearZeros(lv);
  ClearZeros(rv);
  if (IsNull(*lv)) lv->bits[3] = rv->bits[3];
  if (IsNull(*rv)) rv->bits[3] = lv->bits[3];
  if (ScaleGetter(rv) > ScaleGetter(lv)) {
    low = lv;
    high = rv;
  } else {
    low = rv;
    high = lv;
  }
  char low_scale = ScaleGetter(low);
  char high_scale = ScaleGetter(high);

  while (low_scale < high_scale && !mul10(low)) {
    ScaleSetter(low, ++low_scale);
  }
  unsigned save_mod = 0, counter = 0;
  while (low_scale < high_scale) {
    counter++;
    s21_decimal mod;
    save_mod /= 10;
    div10(high, &mod);
    save_mod += mod.bits[0] * 10;
    ScaleSetter(high, --high_scale);
    if (high_scale == low_scale) {
      if (!(save_mod % 10) && counter > 1) save_mod++;
      g_mod = (int)save_mod;
    }
  }
  int ret = !save_mod ? 0 : (high == rv ? 1 : -1);
  g_mod *= ret;
  return ret;
}

void RoundToScale(s21_decimal *num, char to_scale) {
  char scale = ScaleGetter(num);

  if (scale > to_scale) {
    ScaleSetter(num, (char)(scale - to_scale));
    s21_round(*num, num);
    ScaleSetter(num, to_scale);
  }
}