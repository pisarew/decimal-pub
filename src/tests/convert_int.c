//
// Created by ruslan on 18.01.23.
//
#include "tests.h"

#include <check.h>
#include <stdint.h>

#include "s21_decimal.h"

START_TEST(convert_int_check_decimal_00) {
  int number = 0;
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_int_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}

START_TEST(convert_int_check_decimal_01) {
  int number = 1;
  s21_decimal decimal_number = {{0x01, 0x0, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_int_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}

START_TEST(convert_int_check_decimal_02) {
  int number = -1;
  s21_decimal decimal_number = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_int_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}

START_TEST(convert_int_check_decimal_03) {
  int number = INT32_MAX;
  s21_decimal decimal_number = {{INT32_MAX, 0x0, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_int_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}

START_TEST(convert_int_check_decimal_04) {
  int number = INT32_MIN;
  s21_decimal decimal_number = {{(unsigned) INT32_MAX + 1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_int_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}

START_TEST(convert_int_check_decimal_05) {
  int number = 112345678;
  s21_decimal decimal_number = {{112345678, 0x0, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_int_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}

START_TEST(convert_int_check_decimal_06) {
  int number = -112345678;
  s21_decimal decimal_number = {{112345678, 0x0, 0x0, 0x80000000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_int_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}

START_TEST(convert_int_check_int_00) {
  int number = -1;
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x80000000}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_01) {
  int number = 1;
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x0}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_02) {
  int number = 0;
  s21_decimal decimal_number = {{0, 0x0, 0x0, 0x0}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_03) {
  int number = INT32_MAX;
  s21_decimal decimal_number = {{INT32_MAX, 0x0, 0x0, 0x0}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_04) {
  int number = INT32_MIN;
  s21_decimal decimal_number = {{(unsigned) INT32_MAX + 1, 0x0, 0x0, 0x80000000}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_05) {
  int number = -112345678;
  s21_decimal decimal_number = {{112345678, 0x0, 0x0, 0x80000000}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_06) {
  int number = 112345678;
  s21_decimal decimal_number = {{112345678, 0x0, 0x0, 0x0}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

//  bits[3] - 0 or 8  - sign | 0 | __ - exp | 0000

START_TEST(convert_int_check_int_07) {
  int number = 42949672;
  s21_decimal decimal_number = {{UINT32_MAX, 0x0, 0x0, 0x00020000}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_08) {
  int number = 42949672;
  s21_decimal decimal_number = {{UINT32_MAX, 0x0, 0x0, 0x00020000}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_09) {
  int number = 165182414;
  s21_decimal decimal_number = {{4100111000, 25489954, 895455662, 0x00140000}};// 355F91AE  0184F222  F462BA98
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_10) {
  int number = -165182414;
  s21_decimal decimal_number = {{4100111000, 25489954, 895455662, 0x80140000}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 0);
  ck_assert_int_eq(number, result);
}

START_TEST(convert_int_check_int_11) {
  s21_decimal decimal_number = {{112345678, 0x1, 0x0, 0x0}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 1);
}

START_TEST(convert_int_check_int_12) {
  s21_decimal decimal_number = {{(unsigned) INT32_MAX + 1, 0x0, 0x0, 0x0}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 1);
}

START_TEST(convert_int_check_int_13) {
  s21_decimal decimal_number = {{4100111000, 25489954, 895455662, 0x000f0000}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 1);
}

START_TEST(convert_int_check_int_14) {
  s21_decimal decimal_number = {{4100111000, 25489954, 895455662, 0x800f0000}};
  int result;

  ck_assert_int_eq(s21_from_decimal_to_int(decimal_number, &result), 1);
}

Suite *convert_int_suite(void) {
  Suite *s = suite_create("Convert_int");
  TCase *tc_core = tcase_create("Convert_int");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, convert_int_check_decimal_00);
  tcase_add_test(tc_core, convert_int_check_decimal_01);
  tcase_add_test(tc_core, convert_int_check_decimal_02);
  tcase_add_test(tc_core, convert_int_check_decimal_03);
  tcase_add_test(tc_core, convert_int_check_decimal_04);
  tcase_add_test(tc_core, convert_int_check_decimal_05);
  tcase_add_test(tc_core, convert_int_check_decimal_06);

  tcase_add_test(tc_core, convert_int_check_int_00);
  tcase_add_test(tc_core, convert_int_check_int_01);
  tcase_add_test(tc_core, convert_int_check_int_02);
  tcase_add_test(tc_core, convert_int_check_int_03);
  tcase_add_test(tc_core, convert_int_check_int_04);
  tcase_add_test(tc_core, convert_int_check_int_05);
  tcase_add_test(tc_core, convert_int_check_int_06);
  tcase_add_test(tc_core, convert_int_check_int_07);
  tcase_add_test(tc_core, convert_int_check_int_08);
  tcase_add_test(tc_core, convert_int_check_int_09);
  tcase_add_test(tc_core, convert_int_check_int_10);
  tcase_add_test(tc_core, convert_int_check_int_11);
  tcase_add_test(tc_core, convert_int_check_int_12);
  tcase_add_test(tc_core, convert_int_check_int_13);
  tcase_add_test(tc_core, convert_int_check_int_14);

  return s;
}
