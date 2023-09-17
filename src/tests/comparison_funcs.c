//
// Created by Глеб Писарев on 25.01.2023.
//
#include "tests.h"

#include <check.h>

#include "s21_decimal.h"

START_TEST(comparison_check_is_less_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_less_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_less_02) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_less_03) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{13, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_less_04) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00070000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_less_05) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_less_or_equal_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_less_or_equal_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_less_or_equal_02) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_less_or_equal_03) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{13, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_less_or_equal_04) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00070000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_less_or_equal_05) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_greater_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_greater_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_greater_02) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_greater_03) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{13, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_greater_04) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00070000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_greater_05) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_greater_or_equal_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_greater_or_equal_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_greater_or_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_greater_or_equal_02) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_greater_or_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_greater_or_equal_03) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{13, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_greater_or_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_greater_or_equal_04) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00070000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_greater_or_equal_05) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_equal_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_equal_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_equal_02) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_equal_03) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{13, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_equal_04) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00070000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(comparison_check_is_equal_05) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_not_equal_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_not_equal_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_not_equal_02) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_not_equal_03) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{13, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_not_equal_04) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00070000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(comparison_check_is_not_equal_05) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(s21_is_not_equal(a, b), 0);
}
END_TEST

Suite *comparison_suite(void) {
  Suite *s = suite_create("Comparison");
  TCase *tc_core = tcase_create("Comparison");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, comparison_check_is_less_00);
  tcase_add_test(tc_core, comparison_check_is_less_01);
  tcase_add_test(tc_core, comparison_check_is_less_02);
  tcase_add_test(tc_core, comparison_check_is_less_03);
  tcase_add_test(tc_core, comparison_check_is_less_04);
  tcase_add_test(tc_core, comparison_check_is_less_05);

  tcase_add_test(tc_core, comparison_check_is_less_or_equal_00);
  tcase_add_test(tc_core, comparison_check_is_less_or_equal_01);
  tcase_add_test(tc_core, comparison_check_is_less_or_equal_02);
  tcase_add_test(tc_core, comparison_check_is_less_or_equal_03);
  tcase_add_test(tc_core, comparison_check_is_less_or_equal_04);
  tcase_add_test(tc_core, comparison_check_is_less_or_equal_05);

  tcase_add_test(tc_core, comparison_check_is_greater_00);
  tcase_add_test(tc_core, comparison_check_is_greater_01);
  tcase_add_test(tc_core, comparison_check_is_greater_02);
  tcase_add_test(tc_core, comparison_check_is_greater_03);
  tcase_add_test(tc_core, comparison_check_is_greater_04);
  tcase_add_test(tc_core, comparison_check_is_greater_05);

  tcase_add_test(tc_core, comparison_check_is_greater_or_equal_00);
  tcase_add_test(tc_core, comparison_check_is_greater_or_equal_01);
  tcase_add_test(tc_core, comparison_check_is_greater_or_equal_02);
  tcase_add_test(tc_core, comparison_check_is_greater_or_equal_03);
  tcase_add_test(tc_core, comparison_check_is_greater_or_equal_04);
  tcase_add_test(tc_core, comparison_check_is_greater_or_equal_05);

  tcase_add_test(tc_core, comparison_check_is_equal_00);
  tcase_add_test(tc_core, comparison_check_is_equal_01);
  tcase_add_test(tc_core, comparison_check_is_equal_02);
  tcase_add_test(tc_core, comparison_check_is_equal_03);
  tcase_add_test(tc_core, comparison_check_is_equal_04);
  tcase_add_test(tc_core, comparison_check_is_equal_05);

  tcase_add_test(tc_core, comparison_check_is_not_equal_00);
  tcase_add_test(tc_core, comparison_check_is_not_equal_01);
  tcase_add_test(tc_core, comparison_check_is_not_equal_02);
  tcase_add_test(tc_core, comparison_check_is_not_equal_03);
  tcase_add_test(tc_core, comparison_check_is_not_equal_04);
  tcase_add_test(tc_core, comparison_check_is_not_equal_05);

  return s;
}