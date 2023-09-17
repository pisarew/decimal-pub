//
// Created by Глеб Писарев on 25.01.2023.
//
#include "tests.h"

#include <check.h>

#include "s21_decimal.h"

START_TEST(arithmetic_check_mul_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{3078075, 0x0, 0x0, 0x00040000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{3078075, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_02) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x80010000}};
  s21_decimal decimal_number = {{3078075, 0x0, 0x0, 0x00040000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_03) {
  s21_decimal a = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{2, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x33333333, 0x33333333, 0x33333333, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_04) {
  s21_decimal a = {{0xE4003039, 0xDCC80CD2, 0x0052B7D2, 0x00050000}};             // 1000000000000000000000.12345
  s21_decimal b = {{1505, 0x0, 0x0, 0x00030000}};                                 // 1.505
  s21_decimal decimal_number = {{0x0A1C5982, 0xCB9B89FB, 0x30A11176, 0x00070000}};// идеальное вольфрам 15050000000000000000000.18579225
  s21_decimal result;                                                             // C# result 1505000000000000000000.1857922
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_05) {
  s21_decimal a = {{0xE4003039, 0xDCC80CD2, 0x0052B7D2, 0x00050000}};             // 1000000000000000000000.12345
  s21_decimal b = {{1505, 0x0, 0x0, 0x00030000}};                                 // 1.505
  s21_decimal decimal_number = {{0x0A1C5982, 0xCB9B89FB, 0x30A11176, 0x00070000}};// идеальное вольфрам 15050000000000000000000.18594275
  s21_decimal result;                                                             // C# result 1505000000000000000000.1859428
  //                               1505000000000000000000.1857922
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_06) {
  s21_decimal a = {{1, 0x0, 0x0, 0x00110000}};
  s21_decimal b = {{1, 0x0, 0x0, 0x00110000}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_07) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{123123, 0x0, 0x0, 0x001C0000}};
  s21_decimal decimal_number = {{975481, 0x0, 0x0, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_08) {
  s21_decimal a = {{51, 0x0, 0x0, 0x001A0000}};// scale 25
  s21_decimal b = {{1, 0x0, 0x0, 0x00040000}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_09) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_10) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_11) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_12) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_13) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{2, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 1);
}
END_TEST

START_TEST(arithmetic_check_mul_14) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{2, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 2);
}
END_TEST

START_TEST(arithmetic_check_mul_15) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{2, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 1);
}
END_TEST

START_TEST(arithmetic_check_mul_16) {
  s21_decimal a = {{1024, 0x0, 0x0, 0x0}};
  s21_decimal b = {{4, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{4096, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_17) {
  s21_decimal a = {{233, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{92985, 0x0, 0x0, 0x00040000}};
  s21_decimal decimal_number = {{21665505, 0x0, 0x0, 0x00050000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_18) {
  s21_decimal a = {{233, 0x0, 0x0, 0x80010000}};
  s21_decimal b = {{92985, 0x0, 0x0, 0x00040000}};
  s21_decimal decimal_number = {{21665505, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_19) {
  s21_decimal a = {{1, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{3, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{3, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_20) {
  s21_decimal a = {{1000, 0x0, 0x0, 0x0}};
  s21_decimal b = {{7, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{7000, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_21) {
  s21_decimal a = {{1000, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{7, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{7000, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_22) {
  s21_decimal a = {{1230000000, 0x0, 0x0, 0x00070000}};
  s21_decimal b = {{12300, 0x0, 0x0, 0x00070000}};
  s21_decimal decimal_number = {{15129, 0x0, 0x0, 0x00050000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_23) {
  s21_decimal a = {{0x5D587500, 0x002BDC54, 0x0, 0x0}};
  s21_decimal b = {{12345678, 0x0, 0x0, 0x00100000}};
  s21_decimal decimal_number = {{0xA2197166, 0x00056A36, 0x0, 0x00080000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_24) {
  s21_decimal a = {{0x7DE98115, 0x112210F4, 0x0, 0x000A0000}};
  s21_decimal b = {{0xB9844B15, 0x112210F4, 0x0, 0x000A0000}};
  s21_decimal decimal_number = {{0x5CED3186, 0x7CDF5CC5, 0x313F89D8, 0x000C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_25) {
  s21_decimal a = {{12300, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{27183, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_26) {
  s21_decimal a = {{12301, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2718521, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_27) {
  s21_decimal a = {{12302, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2718742, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_28) {
  s21_decimal a = {{12303, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2718963, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_29) {
  s21_decimal a = {{12304, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2719184, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_30) {
  s21_decimal a = {{12305, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2719405, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_31) {
  s21_decimal a = {{12306, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2719626, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_32) {
  s21_decimal a = {{12307, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2719847, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_33) {
  s21_decimal a = {{12308, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2720068, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_34) {
  s21_decimal a = {{12309, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2720289, 0x0, 0x0, 0x00020000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mul_35) {
  s21_decimal a = {{12310, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{272051, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

Suite *arithmetic_mul_suite(void) {
  Suite *s = suite_create("Arithmetic_mul");
  TCase *tc_core = tcase_create("Arithmetic_mul");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, arithmetic_check_mul_00);
  tcase_add_test(tc_core, arithmetic_check_mul_01);
  tcase_add_test(tc_core, arithmetic_check_mul_02);
  tcase_add_test(tc_core, arithmetic_check_mul_03);
  tcase_add_test(tc_core, arithmetic_check_mul_04);
  tcase_add_test(tc_core, arithmetic_check_mul_05);
  tcase_add_test(tc_core, arithmetic_check_mul_06);
  tcase_add_test(tc_core, arithmetic_check_mul_07);
  tcase_add_test(tc_core, arithmetic_check_mul_08);
  tcase_add_test(tc_core, arithmetic_check_mul_09);
  tcase_add_test(tc_core, arithmetic_check_mul_10);
  tcase_add_test(tc_core, arithmetic_check_mul_11);
  tcase_add_test(tc_core, arithmetic_check_mul_12);
  tcase_add_test(tc_core, arithmetic_check_mul_13);
  tcase_add_test(tc_core, arithmetic_check_mul_14);
  tcase_add_test(tc_core, arithmetic_check_mul_15);
  tcase_add_test(tc_core, arithmetic_check_mul_16);
  tcase_add_test(tc_core, arithmetic_check_mul_17);
  tcase_add_test(tc_core, arithmetic_check_mul_18);
  tcase_add_test(tc_core, arithmetic_check_mul_19);
  tcase_add_test(tc_core, arithmetic_check_mul_20);
  tcase_add_test(tc_core, arithmetic_check_mul_21);
  tcase_add_test(tc_core, arithmetic_check_mul_22);
  tcase_add_test(tc_core, arithmetic_check_mul_23);
  tcase_add_test(tc_core, arithmetic_check_mul_24);
  tcase_add_test(tc_core, arithmetic_check_mul_25);
  tcase_add_test(tc_core, arithmetic_check_mul_26);
  tcase_add_test(tc_core, arithmetic_check_mul_27);
  tcase_add_test(tc_core, arithmetic_check_mul_28);
  tcase_add_test(tc_core, arithmetic_check_mul_29);
  tcase_add_test(tc_core, arithmetic_check_mul_30);
  tcase_add_test(tc_core, arithmetic_check_mul_31);
  tcase_add_test(tc_core, arithmetic_check_mul_32);
  tcase_add_test(tc_core, arithmetic_check_mul_33);
  tcase_add_test(tc_core, arithmetic_check_mul_34);
  tcase_add_test(tc_core, arithmetic_check_mul_35);

  return s;
}