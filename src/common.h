//
// Created by ruslan on 19.01.23.
//

#ifndef DECIMAL_SRC_COMMON_H_
#define DECIMAL_SRC_COMMON_H_

#include <stdbool.h>

#include "s21_decimal.h"

#define IsNull(X) (memcmp(&X, &(s21_decimal){}, sizeof(int[3])) == 0)

enum { EMPTY_NUM = -1, OK = 0, HUGE_VAL_ = 1, SMALL_VAL = 2, DIV_BY_ZERO = 3 };

extern int g_mod;

bool BitGetter(const void *byte, char bit);
void BitSetter(void *byte, char bit, bool value);
char ScaleGetter(const void *byte);
void ScaleSetter(void *byte, char scale);
int BitShift(s21_decimal number, char shift, s21_decimal *);
char MSB(s21_decimal number);
void ClearZeros(s21_decimal *);
int Alignment(s21_decimal *, s21_decimal *);
s21_decimal Abs(s21_decimal num);
void AddZeros(s21_decimal *num);
void RoundToScale(s21_decimal *num, char to_scale);

#endif  // DECIMAL_SRC_COMMON_H_
