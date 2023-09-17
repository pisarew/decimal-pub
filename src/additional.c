//
// Created by ruslan on 22.01.23.
//

#include "arithmetic.h"
#include "common.h"
#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  ClearZeros(&value);
  char scale = ScaleGetter(&value);

  for (char i = 0; i < scale; ++i) {
    div10(&value, &(s21_decimal){});
  }
  ScaleSetter(&value, 0);
  if (BitGetter(&value, 127) && scale > 0)
    Add(value, (s21_decimal){{1, 0, 0, 0}}, &value);
  *result = value;
  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = OK;
  ClearZeros(&value);
  char scale = (char)(ScaleGetter(&value));
  s21_decimal mod;

  for (char i = 0; i < scale; ++i) {
    div10(&value, &mod);
  }
  ScaleSetter(&value, 0);
  if (mod.bits[0] > 5 ||
      (mod.bits[0] == 5 && (scale > 1 || (!Div(value, (s21_decimal){{10}},
                                               &(s21_decimal){}, &mod) &&
                                          mod.bits[0] % 2))))
    error = Add(value, (s21_decimal){{1}}, &value);
  *result = value;
  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  char scale = ScaleGetter(&value);

  for (char i = 0; i < scale; ++i) {
    div10(&value, &(s21_decimal){});
  }
  ScaleSetter(&value, 0);
  *result = value;
  return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  BitSetter(result, 127, !BitGetter(result, 127));

  return 0;
}