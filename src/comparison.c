//
// Created by ruslan on 22.01.23.
//

#include "comparison.h"

#include <string.h>

#include "common.h"
#include "s21_decimal.h"

int s21_is_less(s21_decimal lv, s21_decimal rv) {
  int ret = 0;
  bool lv_sign = BitGetter(&lv, 127);
  bool rv_sign = BitGetter(&rv, 127);
  if (lv_sign > rv_sign) {
    ret = 1;
  } else if (lv_sign == rv_sign) {
    int cmp = Alignment(&lv, &rv);
    if (cmp == -1 || (!cmp && IsLess(lv, rv))) ret = 1;
    if (lv_sign == 1) ret = !ret;
  }
  return ret;
}

int IsLess(s21_decimal lv, s21_decimal rv) {
  int ret = 0;
  char lmsb = MSB(lv);
  char rmsb = MSB(rv);

  if (lmsb < rmsb) {
    ret = 1;
  } else if (lmsb == rmsb) {
    char i;
    for (i = lmsb; i >= 0 && BitGetter(&lv, i) == BitGetter(&rv, i); --i)
      ;
    if (i >= 0 && BitGetter(&lv, i) < BitGetter(&rv, i)) ret = 1;
  }
  return ret;
}

int s21_is_less_or_equal(s21_decimal lv, s21_decimal rv) {
  return s21_is_equal(lv, rv) || s21_is_less(lv, rv);
}

int s21_is_greater(s21_decimal lv, s21_decimal rv) {
  return !s21_is_less_or_equal(lv, rv);
}

int s21_is_greater_or_equal(s21_decimal lv, s21_decimal rv) {
  return !s21_is_less(lv, rv);
}

int s21_is_equal(s21_decimal lv, s21_decimal rv) {
  Alignment(&lv, &rv);
  return !memcmp(&lv, &rv, sizeof(s21_decimal));
}

int s21_is_not_equal(s21_decimal lv, s21_decimal rv) {
  return !s21_is_equal(lv, rv);
}