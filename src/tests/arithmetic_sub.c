//
// Created by Глеб Писарев on 25.01.2023.
//
#include "tests.h"

#include <check.h>

#include "s21_decimal.h"

END_TEST

START_TEST(arithmetic_check_sub_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{100000, 0x0, 0x0, 0x80030000}};
  s21_decimal decimal_number = {{223123, 0x0, 0x0, 0x00030000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{100000, 0x0, 0x0, 0x00030000}};
  s21_decimal decimal_number = {{123223, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_02) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00000000}};
  s21_decimal b = {{100000, 0x0, 0x0, 0x00030000}};
  s21_decimal decimal_number = {{123023, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_03) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{100000, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{23123, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_04) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{1400, 0x0, 0x0, 0x00030000}};
  s21_decimal decimal_number = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_05) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_06) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_07) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_08) {
  s21_decimal a = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_09) {
  s21_decimal a = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_10) {
  s21_decimal a = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{1, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{2, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_11) {
  s21_decimal a = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal) - sizeof(int));
}
END_TEST

START_TEST(arithmetic_check_sub_12) {
  s21_decimal a = {{1, 0x0, 0x0, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal_number = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_13) {
  s21_decimal a = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 1);
}
END_TEST

START_TEST(arithmetic_check_sub_14) {
  s21_decimal a = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal decimal_number = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_15) {
  s21_decimal a = {{1, 0x0, 0x0, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 1);
}
END_TEST

START_TEST(arithmetic_check_sub_16) {
  s21_decimal a = {{14, 0x0, 0x0, 0x0}};
  s21_decimal b = {{0x70000000, 0xB30310A7, 0xE22EA493, 0x001C0000}};
  s21_decimal decimal_number = {{7, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_17) {
  s21_decimal a = {{0x0, 0x00010000, 0x0, 0x00080000}};
  s21_decimal b = {{0x0, 0x00010000, 0x0, 0x80030000}};
  s21_decimal decimal_number = {{0x0, 0x86A10000, 0x00000001, 0x00080000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_18) {
  s21_decimal a = {{0x0, 0x00010000, 0x0, 0x0}};
  s21_decimal b = {{0x0, 0x00010000, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{0x0, 0x00020000, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_19) {
  s21_decimal a = {{123, 0x0, 0x0, 0x001C0000}};
  s21_decimal b = {{1, 0x0, 0x0, 0x801C0000}};
  s21_decimal decimal_number = {{124, 0x0, 0x0, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_20) {
  s21_decimal a = {{0x0, 0x00010000, 0x0, 0x80080000}};
  s21_decimal b = {{0x0, 0x00010000, 0x0, 0x80030000}};
  s21_decimal decimal_number = {{0x0, 0x869F0000, 0x00000001, 0x00080000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_21) {
  s21_decimal a = {{0x0, 0x00010000, 0x0, 0x0}};
  s21_decimal b = {{0x0, 0x00010000, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_22) {
  s21_decimal a = {{123, 0x0, 0x0, 0x801C0000}};
  s21_decimal b = {{1, 0x0, 0x0, 0x801C0000}};
  s21_decimal decimal_number = {{122, 0x0, 0x0, 0x801C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_23) {
  s21_decimal a = {{0x0, 0x00010000, 0x0, 0x00080000}};
  s21_decimal b = {{0x0, 0x00010000, 0x0, 0x00030000}};
  s21_decimal decimal_number = {{0x0, 0x869F0000, 0x00000001, 0x80080000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_24) {
  s21_decimal a = {{0x0, 0x00010000, 0x0, 0x80000000}};
  s21_decimal b = {{0x0, 0x00010000, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x00020000, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_sub_25) {
  s21_decimal a = {{123, 0x0, 0x0, 0x001C0000}};
  s21_decimal b = {{1, 0x0, 0x0, 0x001C0000}};
  s21_decimal decimal_number = {{122, 0x0, 0x0, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

Suite *arithmetic_sub_suite(void) {
  Suite *s = suite_create("Arithmetic_sub");
  TCase *tc_core = tcase_create("Arithmetic_sub");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, arithmetic_check_sub_00);
  tcase_add_test(tc_core, arithmetic_check_sub_01);
  tcase_add_test(tc_core, arithmetic_check_sub_02);
  tcase_add_test(tc_core, arithmetic_check_sub_03);
  tcase_add_test(tc_core, arithmetic_check_sub_04);
  tcase_add_test(tc_core, arithmetic_check_sub_05);
  tcase_add_test(tc_core, arithmetic_check_sub_06);
  tcase_add_test(tc_core, arithmetic_check_sub_07);
  tcase_add_test(tc_core, arithmetic_check_sub_08);
  tcase_add_test(tc_core, arithmetic_check_sub_09);
  tcase_add_test(tc_core, arithmetic_check_sub_10);
  tcase_add_test(tc_core, arithmetic_check_sub_11);
  tcase_add_test(tc_core, arithmetic_check_sub_12);
  tcase_add_test(tc_core, arithmetic_check_sub_13);
  tcase_add_test(tc_core, arithmetic_check_sub_14);
  tcase_add_test(tc_core, arithmetic_check_sub_15);
  tcase_add_test(tc_core, arithmetic_check_sub_16);
  tcase_add_test(tc_core, arithmetic_check_sub_17);
  tcase_add_test(tc_core, arithmetic_check_sub_18);
  tcase_add_test(tc_core, arithmetic_check_sub_19);
  tcase_add_test(tc_core, arithmetic_check_sub_20);
  tcase_add_test(tc_core, arithmetic_check_sub_21);
  tcase_add_test(tc_core, arithmetic_check_sub_22);
  tcase_add_test(tc_core, arithmetic_check_sub_23);
  tcase_add_test(tc_core, arithmetic_check_sub_24);
  tcase_add_test(tc_core, arithmetic_check_sub_25);

  return s;
}