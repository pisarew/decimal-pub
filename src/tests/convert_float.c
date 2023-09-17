//
// Created by ruslan on 19.01.23.
//

#include "tests.h"

#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_decimal.h"

START_TEST(convert_float_check_decimal_00) {
  float number = 0;
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_01) {
  float number = 1;
  s21_decimal decimal_number = {{0x01, 0x0, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_02) {
  float number = -1;
  s21_decimal decimal_number = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_03) {
  float number = 123.123f;
  s21_decimal decimal_number = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_04) {
  float number = -123.123f;
  s21_decimal decimal_number = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_05) {
  float number = 12312311112.0f;
  s21_decimal decimal_number = {{0xDDDEF0F0, 0x00000002, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_06) {
  float number = -12312311112.0f;
  s21_decimal decimal_number = {{3722375408, 0x02, 0x0, 0x80000000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_07) {
  float number = 0.12312311112f;
  s21_decimal decimal_number = {{1231231, 0x0, 0x0, 0x00070000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_08) {
  float number = -0.12312311112f;
  s21_decimal decimal_number = {{1231231, 0x0, 0x0, 0x80070000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_09) {
  float number = 1231.2311112f;
  s21_decimal decimal_number = {{1231231, 0x0, 0x0, 0x00030000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_10) {
  float number = -1231.2311112f;
  s21_decimal decimal_number = {{1231231, 0x0, 0x0, 0x80030000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_11) {
  float number = 12312316112.0f;
  s21_decimal decimal_number = {{0xDDDEF0F1, 0x00000002, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_12) {
  float number = -12312316112.0f;
  s21_decimal decimal_number = {{0xDDDEF0F1, 0x02, 0x0, 0x80000000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_13) {
  float number = 0.12312325112f;
  s21_decimal decimal_number = {{1231233, 0x0, 0x0, 0x00070000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_14) {
  float number = -0.12312325112f;
  s21_decimal decimal_number = {{1231233, 0x0, 0x0, 0x80070000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_15) {
  float number = 1231.2306112f;
  s21_decimal decimal_number = {{1231231, 0x0, 0x0, 0x00030000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_16) {
  float number = -1231.2306112f;
  s21_decimal decimal_number = {{1231231, 0x0, 0x0, 0x80030000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_17) {
  float number = (float) 1e-29;
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 1);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_18) {
  float number = FLT_MAX;
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 1);
}
END_TEST

START_TEST(convert_float_check_decimal_19) {
  float number = NAN;
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 1);
}
END_TEST

START_TEST(convert_float_check_decimal_20) {
  float number = INFINITY;
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 1);
}
END_TEST

START_TEST(convert_float_check_decimal_21) {
  float number = -INFINITY;
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 1);
}
END_TEST

START_TEST(convert_float_check_decimal_22) {
  float number = -FLT_MAX;
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 1);
}
END_TEST

START_TEST(convert_float_check_decimal_23) {
  float number = (float) 2e-28;
  s21_decimal decimal_number = {{2, 0x0, 0x0, 0x001C0000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_24) {
  float number = 7.9228162514264337593543950335;
  s21_decimal decimal_number = {{7922816, 0x0, 0x0, 0x00060000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_decimal_25) {
  float number = -7.9228162514264337593543950335;
  s21_decimal decimal_number = {{7922816, 0x0, 0x0, 0x80060000}};
  s21_decimal result;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(convert_float_check_float_00) {
  float number = -1;
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x80000000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq(number, result);
}
END_TEST

START_TEST(convert_float_check_float_01) {
  float number = 1;
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x0}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq(number, result);
}
END_TEST

START_TEST(convert_float_check_float_02) {
  float number = 0;
  s21_decimal decimal_number = {{0, 0x0, 0x0, 0x0}};
  float result;

  ck_assert_float_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq(number, result);
}
END_TEST

START_TEST(convert_float_check_float_03) {
  float number = 123.123f;
  s21_decimal decimal_number = {{123123, 0x0, 0x0, 0x00030000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq_tol(number, result, 1e-3);
}
END_TEST

START_TEST(convert_float_check_float_04) {
  float number = -123.123f;
  s21_decimal decimal_number = {{123123, 0x0, 0x0, 0x80030000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq_tol(number, result, 1e-3);
}
END_TEST

START_TEST(convert_float_check_float_05) {
  float number = 12312311112.0f;
  s21_decimal decimal_number = {{3722375408, 0x00000002, 0x0, 0x0000000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq_tol(number, result, 1e4);
}
END_TEST

START_TEST(convert_float_check_float_06) {
  float number = -12312311112.0f;
  s21_decimal decimal_number = {{3722375408, 0x02, 0x0, 0x80000000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq_tol(number, result, 1e4);
}
END_TEST

START_TEST(convert_float_check_float_07) {
  float number = 0.12312311112f;
  s21_decimal decimal_number = {{1231231, 0x0, 0x0, 0x00070000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq_tol(number, result, 1e-7);
}
END_TEST

START_TEST(convert_float_check_float_08) {
  float number = -0.12312311112f;
  s21_decimal decimal_number = {{1231231, 0x0, 0x0, 0x80070000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq_tol(number, result, 1e-7);
}
END_TEST

START_TEST(convert_float_check_float_09) {
  float number = 7.922816e28f;
  s21_decimal decimal_number = {{0xffffffff, 0xffffffff, 0xffffffff, 0x00000000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq_tol(number, result, 1e22);
}
END_TEST

START_TEST(convert_float_check_float_10) {
  float number = -7.922816e28f;
  s21_decimal decimal_number = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80000000}};
  float result;

  ck_assert_int_eq(s21_from_decimal_to_float(decimal_number, &result), 0);
  ck_assert_float_eq_tol(number, result, 1e22);
}
END_TEST

Suite *convert_float_suite(void) {
  Suite *s = suite_create("Convert_float");
  TCase *tc_core = tcase_create("Convert_float");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, convert_float_check_decimal_00);
  tcase_add_test(tc_core, convert_float_check_decimal_01);
  tcase_add_test(tc_core, convert_float_check_decimal_02);
  tcase_add_test(tc_core, convert_float_check_decimal_03);
  tcase_add_test(tc_core, convert_float_check_decimal_04);
  tcase_add_test(tc_core, convert_float_check_decimal_05);
  tcase_add_test(tc_core, convert_float_check_decimal_06);
  tcase_add_test(tc_core, convert_float_check_decimal_07);
  tcase_add_test(tc_core, convert_float_check_decimal_08);
  tcase_add_test(tc_core, convert_float_check_decimal_09);
  tcase_add_test(tc_core, convert_float_check_decimal_10);
  tcase_add_test(tc_core, convert_float_check_decimal_11);
  tcase_add_test(tc_core, convert_float_check_decimal_12);
  tcase_add_test(tc_core, convert_float_check_decimal_13);
  tcase_add_test(tc_core, convert_float_check_decimal_14);
  tcase_add_test(tc_core, convert_float_check_decimal_15);
  tcase_add_test(tc_core, convert_float_check_decimal_16);
  tcase_add_test(tc_core, convert_float_check_decimal_17);
  tcase_add_test(tc_core, convert_float_check_decimal_18);
  tcase_add_test(tc_core, convert_float_check_decimal_19);
  tcase_add_test(tc_core, convert_float_check_decimal_20);
  tcase_add_test(tc_core, convert_float_check_decimal_21);
  tcase_add_test(tc_core, convert_float_check_decimal_22);
  tcase_add_test(tc_core, convert_float_check_decimal_23);
  tcase_add_test(tc_core, convert_float_check_decimal_24);
  tcase_add_test(tc_core, convert_float_check_decimal_25);

  tcase_add_test(tc_core, convert_float_check_float_00);
  tcase_add_test(tc_core, convert_float_check_float_01);
  tcase_add_test(tc_core, convert_float_check_float_02);
  tcase_add_test(tc_core, convert_float_check_float_03);
  tcase_add_test(tc_core, convert_float_check_float_04);
  tcase_add_test(tc_core, convert_float_check_float_05);
  tcase_add_test(tc_core, convert_float_check_float_06);
  tcase_add_test(tc_core, convert_float_check_float_07);
  tcase_add_test(tc_core, convert_float_check_float_08);
  tcase_add_test(tc_core, convert_float_check_float_09);
  tcase_add_test(tc_core, convert_float_check_float_10);

  return s;
}