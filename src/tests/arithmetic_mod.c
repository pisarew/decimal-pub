//
// Created by Глеб Писарев on 25.01.2023.
//
#include "tests.h"

#include <check.h>

#include "s21_decimal.h"

START_TEST(arithmetic_check_mod_00) {
  s21_decimal a = {{1, 0x0, 0x0, 0x0}};
  s21_decimal b = {{3, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_01) {
  s21_decimal a = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{3, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_02) {
  s21_decimal a = {{1, 0x0, 0x0, 0x0}};
  s21_decimal b = {{3, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_03) {
  s21_decimal a = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{3, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_04) {
  s21_decimal a = {{1, 0x0, 0x0, 0x0}};
  s21_decimal b = {{3, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(b, a, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_05) {
  s21_decimal a = {{0x70000000, 0xB30310A7, 0xE22EA493, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x00030000}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x00030000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_06) {
  s21_decimal a = {{0x0, 0x00040000, 0x0, 0x00060000}};          // 1125899906.842624
  s21_decimal b = {{5, 0x0, 0x0, 0x0}};                          // 5
  s21_decimal decimal_number = {{1842624, 0x0, 0x0, 0x00060000}};// 1.842624
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_07) {
  s21_decimal a = {{0x0, 0x00040000, 0x0, 0x00060000}};          // 1125899906.842624
  s21_decimal b = {{5, 0x0, 0x0, 0x0}};                          // 5
  s21_decimal decimal_number = {{1842624, 0x0, 0x0, 0x00060000}};// 1.842624
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_08) {
  s21_decimal a = {{0x0, 0x00040000, 0x0, 0x00060000}};         // 1125899906.842624
  s21_decimal b = {{11, 0x0, 0x0, 0x00010000}};                 // 1.1
  s21_decimal decimal_number = {{942624, 0x0, 0x0, 0x00060000}};// 0.942624
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_09) {
  s21_decimal a = {{0x0, 0x00040000, 0x0, 0x0}};            // 1125899906842624
  s21_decimal b = {{111, 0x0, 0x0, 0x00020000}};            // 1.11
  s21_decimal decimal_number = {{40, 0x0, 0x0, 0x00020000}};// 0.40
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_10) {
  s21_decimal a = {{0x0, 0x00040000, 0x0, 0x0}};// 1125899906842624
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 3);
}
END_TEST

START_TEST(arithmetic_check_mod_11) {
  s21_decimal a = {{48, 0x0, 0x0, 0x0}};
  s21_decimal b = {{6, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_12) {
  s21_decimal a = {{90, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{9, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_13) {
  s21_decimal a = {{1024, 0x0, 0x0, 0x0}};
  s21_decimal b = {{4, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_14) {
  s21_decimal a = {{233, 0x0, 0x0, 0x00010000}};  // 23.3
  s21_decimal b = {{92985, 0x0, 0x0, 0x00040000}};// 9.2985
  s21_decimal decimal_number = {{47030, 0x0, 0x0, 0x00040000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_15) {
  s21_decimal a = {{1, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{3, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_16) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal_number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_17) {
  s21_decimal a = {{1000, 0x0, 0x0, 0x0}};
  s21_decimal b = {{7, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{6, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_18) {
  s21_decimal a = {{1000, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{7, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{6, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_19) {
  s21_decimal a = {{1230000000, 0x0, 0x0, 0x00070000}};
  s21_decimal b = {{12300, 0x0, 0x0, 0x00070000}};
  s21_decimal decimal_number = {{0, 0x0, 0x0, 0x00070000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_20) {
  s21_decimal a = {{0x5D587500, 0x002BDC54, 0x0, 0x0}};
  s21_decimal b = {{12345678, 0x0, 0x0, 0x00100000}};
  s21_decimal decimal_number = {{9832122, 0x0, 0x0, 0x00100000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_21) {
  s21_decimal a = {{0x7DE98115, 0x112210F4, 0x0, 0x000A0000}};
  s21_decimal b = {{0xB9844B15, 0x112210F4, 0x0, 0x000A0000}};
  s21_decimal decimal_number = {{0x7DE98115, 0x112210F4, 0x0, 0x000A0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_22) {
  s21_decimal a = {{12300, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{145, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_23) {
  s21_decimal a = {{12301, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{146, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_24) {
  s21_decimal a = {{12302, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{147, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_25) {
  s21_decimal a = {{12303, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{148, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_26) {
  s21_decimal a = {{12304, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{149, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_27) {
  s21_decimal a = {{12305, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{150, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_28) {
  s21_decimal a = {{12306, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{151, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_29) {
  s21_decimal a = {{12307, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{152, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_30) {
  s21_decimal a = {{12308, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{153, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_31) {
  s21_decimal a = {{12309, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{154, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_32) {
  s21_decimal a = {{12310, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{155, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_33) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{12304, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_34) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001B0000}};
  s21_decimal b = {{12305, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_mod_35) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{12306, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{2562, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_mod(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

Suite *arithmetic_mod_suite(void) {
  Suite *s = suite_create("Arithmetic_mod");
  TCase *tc_core = tcase_create("Arithmetic_mod");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, arithmetic_check_mod_00);
  tcase_add_test(tc_core, arithmetic_check_mod_01);
  tcase_add_test(tc_core, arithmetic_check_mod_02);
  tcase_add_test(tc_core, arithmetic_check_mod_03);
  tcase_add_test(tc_core, arithmetic_check_mod_04);
  tcase_add_test(tc_core, arithmetic_check_mod_05);
  tcase_add_test(tc_core, arithmetic_check_mod_06);
  tcase_add_test(tc_core, arithmetic_check_mod_07);
  tcase_add_test(tc_core, arithmetic_check_mod_08);
  tcase_add_test(tc_core, arithmetic_check_mod_09);
  tcase_add_test(tc_core, arithmetic_check_mod_10);
  tcase_add_test(tc_core, arithmetic_check_mod_11);
  tcase_add_test(tc_core, arithmetic_check_mod_12);
  tcase_add_test(tc_core, arithmetic_check_mod_13);
  tcase_add_test(tc_core, arithmetic_check_mod_14);
  tcase_add_test(tc_core, arithmetic_check_mod_15);
  tcase_add_test(tc_core, arithmetic_check_mod_16);
  tcase_add_test(tc_core, arithmetic_check_mod_17);
  tcase_add_test(tc_core, arithmetic_check_mod_18);
  tcase_add_test(tc_core, arithmetic_check_mod_19);
  tcase_add_test(tc_core, arithmetic_check_mod_20);
  tcase_add_test(tc_core, arithmetic_check_mod_21);
  tcase_add_test(tc_core, arithmetic_check_mod_22);
  tcase_add_test(tc_core, arithmetic_check_mod_23);
  tcase_add_test(tc_core, arithmetic_check_mod_24);
  tcase_add_test(tc_core, arithmetic_check_mod_25);
  tcase_add_test(tc_core, arithmetic_check_mod_26);
  tcase_add_test(tc_core, arithmetic_check_mod_27);
  tcase_add_test(tc_core, arithmetic_check_mod_28);
  tcase_add_test(tc_core, arithmetic_check_mod_29);
  tcase_add_test(tc_core, arithmetic_check_mod_30);
  tcase_add_test(tc_core, arithmetic_check_mod_31);
  tcase_add_test(tc_core, arithmetic_check_mod_32);
  tcase_add_test(tc_core, arithmetic_check_mod_33);
  tcase_add_test(tc_core, arithmetic_check_mod_34);
  tcase_add_test(tc_core, arithmetic_check_mod_35);

  return s;
}