//
// Created by ruslan on 19.01.23.
//

#include <math.h>
#include <string.h>

#include "arithmetic.h"
#include "common.h"
#include "s21_decimal.h"

typedef union {
  unsigned int_;
  float flt_;
} un;

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  memset(dst, 0, sizeof(s21_decimal));
  if (src < 0) {
    BitSetter(dst, 127, 1);
    src = -src;
  }
  dst->bits[0] = src;
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = OK;
  if (isnan(src) || isinf(src)) {
    error = HUGE_VAL_;
  } else {
    un vl;
    vl.flt_ = src;
    float sum = 1.0f;
    int exp = 0;
    unsigned div = 2;

    memset(dst, 0, sizeof(s21_decimal));
    for (int i = 22; i >= 0; --i, div = div << 1) {
      sum += 1.0f / (float)div * (float)BitGetter(&vl.int_, (char)i);
    }
    div = 1;
    for (int i = 23; i < 31; ++i, div = div << 1) {
      exp += (int)(BitGetter(&vl.int_, (char)i) * div);
    }
    if (sum != 1.0f || exp) {
      exp -= 127;
      BitSetter(dst, 127, BitGetter(&vl.int_, 31));
      unsigned int_ = (unsigned)roundf(sum * 100000000.0f);
      dst->bits[0] = int_;
      s21_decimal factor = {{10}}, mod = {};
      ScaleSetter(dst, 8);
      if (exp > 0) {
        error = BitShift(*dst, (char)exp, dst);
        char scale = 8;
        while (!error && (dst->bits[2] > 0 || dst->bits[1] > 0 ||
                          dst->bits[0] >= 10000000)) {
          Div(*dst, factor, dst, &mod);
          scale--;
        }
        while (scale < 0) {
          mul10(dst);
          scale++;
        }
        ScaleSetter(dst, scale);
      } else if (exp < 0) {
        AddZeros(dst);
        bool mul = false;
        for (int i = exp; i < 0; ++i) {
          if (!mul && !mul10(dst)) mul = true;
          BitShift(*dst, -1, dst);
        }
        if (mul) Div(*dst, factor, dst, &mod);
        while (dst->bits[0] >= 10000000) {
          Div(*dst, factor, dst, &mod);
          ScaleSetter(dst, (char)(ScaleGetter(dst) - 1));
        }
      }
      if (mod.bits[0] > 4) Add(*dst, (s21_decimal){{1}}, dst);
      if (sum != 0.0 && IsNull(*dst)) error = 1;
      ClearZeros(dst);
    }
  }
  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = HUGE_VAL_;
  s21_decimal max_int = {{2147483647}};
  bool sign = BitGetter(&src, 127);
  if (sign) max_int.bits[0] += 1;
  s21_truncate(src, &src);
  if (s21_is_less_or_equal(Abs(src), max_int)) {
    if (sign) {
      *dst = -(int)(src.bits[0] - 1) - 1;
    } else {
      *dst = (int)src.bits[0];
    }
    error = OK;
  }
  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  float res = 0;
  for (char i = 0; i < 96; ++i) {
    if ((BitGetter(&src, i)) != 0) {
      res += powf(2, i);
    }
  }
  if (BitGetter(&src, 127)) res = -res;
  char scale = ScaleGetter(&src);
  while (scale) {
    res /= 10;
    --scale;
  }
  *dst = res;
  return error;
}
