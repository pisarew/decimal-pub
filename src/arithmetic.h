//
// Created by ruslan on 20.01.23.
//

#ifndef DECIMAL_SRC_ARITHMETIC_H_
#define DECIMAL_SRC_ARITHMETIC_H_

#include "s21_decimal.h"

int Add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int Sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int Div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
        s21_decimal *mod);
int mul10(s21_decimal *);
void div10(s21_decimal *num, s21_decimal *mod);

#endif  // DECIMAL_SRC_ARITHMETIC_H_
