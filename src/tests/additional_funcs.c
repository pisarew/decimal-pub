//
// Created by Глеб Писарев on 25.01.2023.
//
#include "tests.h"

#include <check.h>

#include "s21_decimal.h"

START_TEST(additional_check_floor_00) {
  s21_decimal num = {{15, 0x0, 0x0, 0x00010000}};
  s21_decimal res = {{1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_floor(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_floor_01) {
  s21_decimal num = {{19, 0x0, 0x0, 0x00010000}};
  s21_decimal res = {{1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_floor(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_floor_02) {
  s21_decimal num = {{155, 0x0, 0x0, 0x00020000}};
  s21_decimal res = {{1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_floor(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_floor_03) {
  s21_decimal num = {{15, 0x0, 0x0, 0x80010000}};
  s21_decimal res = {{2, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(s21_floor(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_floor_04) {
  s21_decimal num = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};// 1.0000...01
  s21_decimal res = {{2, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(s21_floor(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_round_00) {
  s21_decimal num = {{15, 0x0, 0x0, 0x00010000}};
  s21_decimal res = {{2, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_round(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_round_01) {
  s21_decimal num = {{149, 0x0, 0x0, 0x00020000}};
  s21_decimal res = {{1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_round(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_round_02) {
  s21_decimal num = {{25, 0x0, 0x0, 0x00010000}};
  s21_decimal res = {{2, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_round(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_round_03) {
  s21_decimal num = {{251, 0x0, 0x0, 0x00020000}};
  s21_decimal res = {{3, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_round(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_round_04) {
  s21_decimal num = {{0xA8000001, 0x9B5C85F2, 0x50C783EB, 0x001C0000}};// 2.5000000000000000000000000001
  s21_decimal res = {{3, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_round(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_round_05) {
  s21_decimal num = {{0xA8000001, 0x9B5C85F2, 0x50C783EB, 0x801C0000}};// 2.5000000000000000000000000001
  s21_decimal res = {{3, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(s21_round(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_round_06) {
  s21_decimal num = {{15, 0x0, 0x0, 0x80010000}};
  s21_decimal res = {{2, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(s21_round(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_truncate_00) {
  s21_decimal num = {{15, 0x0, 0x0, 0x00010000}};
  s21_decimal res = {{1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_truncate(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_truncate_01) {
  s21_decimal num = {{0xA8000001, 0x9B5C85F2, 0x50C783EB, 0x801C0000}};// 2.5000000000000000000000000001
  s21_decimal res = {{2, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(s21_truncate(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_negate_00) {
  s21_decimal num = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal res = {{1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_negate(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

START_TEST(additional_check_negate_01) {
  s21_decimal num = {{1, 0x0, 0x0, 0x0}};
  s21_decimal res = {{1, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(s21_negate(num, &num), 0);
  ck_assert_mem_eq(&res, &num, sizeof(s21_decimal));
}
END_TEST

Suite *additional_suite(void) {
  Suite *s = suite_create("Additional");
  TCase *tc_core = tcase_create("Additional");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, additional_check_floor_00);
  tcase_add_test(tc_core, additional_check_floor_01);
  tcase_add_test(tc_core, additional_check_floor_02);
  tcase_add_test(tc_core, additional_check_floor_03);
  tcase_add_test(tc_core, additional_check_floor_04);

  tcase_add_test(tc_core, additional_check_round_00);
  tcase_add_test(tc_core, additional_check_round_01);
  tcase_add_test(tc_core, additional_check_round_02);
  tcase_add_test(tc_core, additional_check_round_03);
  tcase_add_test(tc_core, additional_check_round_04);
  tcase_add_test(tc_core, additional_check_round_05);
  tcase_add_test(tc_core, additional_check_round_06);

  tcase_add_test(tc_core, additional_check_truncate_00);
  tcase_add_test(tc_core, additional_check_truncate_01);

  tcase_add_test(tc_core, additional_check_negate_00);
  tcase_add_test(tc_core, additional_check_negate_01);

  return s;
}