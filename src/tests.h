//
// Created by ruslan on 18.01.23.
//

#ifndef DECIMAL_SRC_TESTS_H_
#define DECIMAL_SRC_TESTS_H_

#include <check.h>

Suite *convert_int_suite(void);
Suite *convert_float_suite(void);
Suite *arithmetic_add_suite(void);
Suite *arithmetic_sub_suite(void);
Suite *arithmetic_mul_suite(void);
Suite *arithmetic_div_suite(void);
Suite *arithmetic_mod_suite(void);
Suite *comparison_suite(void);
Suite *additional_suite(void);

#endif  // DECIMAL_SRC_TESTS_H_
