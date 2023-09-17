//
// Created by Глеб Писарев on 25.01.2023.
//
#include "tests.h"

#include "s21_decimal.h"
#include <check.h>

START_TEST(arithmetic_check_div_00) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x00030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{492492, 0x0, 0x0, 0x00040000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_01) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{492492, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_02) {
  s21_decimal a = {{123123, 0x0, 0x0, 0x80030000}};
  s21_decimal b = {{25, 0x0, 0x0, 0x80010000}};
  s21_decimal decimal_number = {{492492, 0x0, 0x0, 0x00040000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_03) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{2, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x80000000, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_04) {
  s21_decimal a = {{0x5BC01A37, 0x63F14120, 0x3039ADCC, 0x00080000}};// C# result 149250099828815335334.94450743
  s21_decimal b = {{123456789, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x00010000, 0x000C0000}};// 2^80
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_05) {
  s21_decimal a = {{1, 0x0, 0x0, 0x00110000}};
  s21_decimal b = {{1, 0x0, 0x0, 0x00110000}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_06) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};             // 7.9228162514264337593543950335
  s21_decimal b = {{123123, 0x0, 0x0, 0x001C0000}};                               // 0.0000000000000000000000123123
  s21_decimal decimal_number = {{0xFEC129F1, 0x1B2F920C, 0xCFEC129F, 0x00050000}};// 643487914640354260321336.79601
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_07) {
  s21_decimal a = {{51, 0x0, 0x0, 0x00190000}};// scale 25 0.0000000000000000000000051
  s21_decimal b = {{100000, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{1, 0x0, 0x0, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_08) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 3);
}
END_TEST

START_TEST(arithmetic_check_div_09) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_10) {
  s21_decimal a = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_11) {
  s21_decimal a = {{1, 0x0, 0x0, 0x0}};
  s21_decimal b = {{3, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0x05555555, 0x14B700CB, 0x0AC544CA, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_12) {
  s21_decimal a = {{0x0000000B, 0x0, 0x80000000, 0x00010000}};
  s21_decimal b = {{5, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x9999999C, 0x99999999, 0x19999999, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_13) {
  s21_decimal a = {{48, 0x0, 0x0, 0x0}};
  s21_decimal b = {{6, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{8, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_14) {
  s21_decimal a = {{90, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{9, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{10, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_15) {
  s21_decimal a = {{124, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{4, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal_number = {{31, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_16) {
  s21_decimal a = {{1, 0x0, 0x0, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal_number = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_17) {
  s21_decimal a = {{1, 0x0, 0x0, 0x0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};             // 4140C78940F6A24FDFFC788
  s21_decimal decimal_number = {{0xFDFFC788, 0x940F6A24, 0x04140C78, 0x001C0000}};// 0.1262177448353618888658765704
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_18) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{1, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 1);
}
END_TEST

START_TEST(arithmetic_check_div_19) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal b = {{1, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 2);
}
END_TEST

START_TEST(arithmetic_check_div_20) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};             // 79228162514264337593543950335
  s21_decimal b = {{111, 0x0, 0x0, 0x00020000}};                                  //
  s21_decimal decimal_number = {{0x24E6A170, 0x4E6A1710, 0xE6A17102, 0x00000000}};// 13767229858237275617513066 + 8
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_21) {
  s21_decimal a = {{1000, 0x0, 0x0, 0x0}};
  s21_decimal b = {{7, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0xCDB6DB6E, 0x3434DED3, 0x2E28DDAB, 0x001A0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_22) {
  s21_decimal a = {{1000, 0x0, 0x0, 0x80000000}};
  s21_decimal b = {{7, 0x0, 0x0, 0x0}};
  s21_decimal decimal_number = {{0xCDB6DB6E, 0x3434DED3, 0x2E28DDAB, 0x801A0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_23) {
  s21_decimal a = {{1230000000, 0x0, 0x0, 0x00070000}};
  s21_decimal b = {{12300, 0x0, 0x0, 0x00070000}};
  s21_decimal decimal_number = {{100000, 0x0, 0x0, 0x0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_24) {
  s21_decimal a = {{0x5D587500, 0x002BDC54, 0x0, 0x0}};
  s21_decimal b = {{12345678, 0x0, 0x0, 0x00100000}};
  s21_decimal decimal_number = {{0xE2835FA4, 0xC30D7E56, 0x204FCE85, 0x00030000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_25) {
  s21_decimal a = {{0x7DE98115, 0x112210F4, 0x0, 0x000A0000}};
  s21_decimal b = {{0xB9844B15, 0x112210F4, 0x0, 0x000A0000}};
  s21_decimal decimal_number = {{0x05392F19, 0xCDBC073C, 0x204FCE5D, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_26) {
  s21_decimal a = {{12300, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x1CD081BD, 0xA9CCD22A, 0xB3D5A76C, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_27) {
  s21_decimal a = {{12301, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x8AC04A23, 0x45BEB4A0, 0xB3D9659B, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_28) {
  s21_decimal a = {{12302, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0xF8B01289, 0xE1B09716, 0xB3DD23C9, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_29) {
  s21_decimal a = {{12303, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x669FDAEF, 0x7DA2798D, 0xB3E0E1F8, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_30) {
  s21_decimal a = {{12304, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0xD48FA355, 0x19945C03, 0xB3E4A027, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_31) {
  s21_decimal a = {{12305, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x6D0CBDF9, 0x9227063F, 0x11FDA308, 0x001A0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_32) {
  s21_decimal a = {{12306, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0xB06F3420, 0x517820F0, 0xB3EC1C84, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_33) {
  s21_decimal a = {{12307, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x1E5EFC86, 0xED6A0367, 0xB3EFDAB2, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_34) {
  s21_decimal a = {{12308, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x8C4EC4EC, 0x895BE5DD, 0xB3F398E1, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_35) {
  s21_decimal a = {{12309, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0xFA3E8D52, 0x254DC853, 0xB3F75710, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_36) {
  s21_decimal a = {{12310, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{221, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0xA404A22C, 0xE01FF77A, 0x11FF821F, 0x001A0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_37) {
  s21_decimal a = {{12304, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal decimal_number = {{0x830786AC, 0x05282856, 0x322DF9B3, 0x001A0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_38) {
  s21_decimal a = {{12305, 0x0, 0x0, 0x00010000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001B0000}};
  s21_decimal decimal_number = {{0x638A15F9, 0xCBF5FF3A, 0x322F04F9, 0x001B0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_39) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal b = {{12304, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0xAB1C4BE7, 0x23F403FE, 0x00354394, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_40) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001B0000}};
  s21_decimal b = {{12305, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x1872024A, 0x95606DD9, 0x021498B4, 0x001C0000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

START_TEST(arithmetic_check_div_41) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal b = {{12306, 0x0, 0x0, 0x00010000}};
  s21_decimal decimal_number = {{0x6E8BE0E0, 0x5CF27A67, 0xD0075296, 0x00030000}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_mem_eq(&decimal_number, &result, sizeof(s21_decimal));
}
END_TEST

Suite *arithmetic_div_suite(void) {
  Suite *s = suite_create("Arithmetic_div");
  TCase *tc_core = tcase_create("Arithmetic_div");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, arithmetic_check_div_00);
  tcase_add_test(tc_core, arithmetic_check_div_01);
  tcase_add_test(tc_core, arithmetic_check_div_02);
  tcase_add_test(tc_core, arithmetic_check_div_03);
  tcase_add_test(tc_core, arithmetic_check_div_04);
  tcase_add_test(tc_core, arithmetic_check_div_05);
  tcase_add_test(tc_core, arithmetic_check_div_06);
  tcase_add_test(tc_core, arithmetic_check_div_07);
  tcase_add_test(tc_core, arithmetic_check_div_08);
  tcase_add_test(tc_core, arithmetic_check_div_09);
  tcase_add_test(tc_core, arithmetic_check_div_10);
  tcase_add_test(tc_core, arithmetic_check_div_11);
  tcase_add_test(tc_core, arithmetic_check_div_12);
  tcase_add_test(tc_core, arithmetic_check_div_13);
  tcase_add_test(tc_core, arithmetic_check_div_14);
  tcase_add_test(tc_core, arithmetic_check_div_15);
  tcase_add_test(tc_core, arithmetic_check_div_16);
  tcase_add_test(tc_core, arithmetic_check_div_17);
  tcase_add_test(tc_core, arithmetic_check_div_18);
  tcase_add_test(tc_core, arithmetic_check_div_19);
  tcase_add_test(tc_core, arithmetic_check_div_20);
  tcase_add_test(tc_core, arithmetic_check_div_21);
  tcase_add_test(tc_core, arithmetic_check_div_22);
  tcase_add_test(tc_core, arithmetic_check_div_23);
  tcase_add_test(tc_core, arithmetic_check_div_24);
  tcase_add_test(tc_core, arithmetic_check_div_25);
  tcase_add_test(tc_core, arithmetic_check_div_26);
  tcase_add_test(tc_core, arithmetic_check_div_27);
  tcase_add_test(tc_core, arithmetic_check_div_28);
  tcase_add_test(tc_core, arithmetic_check_div_29);
  tcase_add_test(tc_core, arithmetic_check_div_30);
  tcase_add_test(tc_core, arithmetic_check_div_31);
  tcase_add_test(tc_core, arithmetic_check_div_32);
  tcase_add_test(tc_core, arithmetic_check_div_33);
  tcase_add_test(tc_core, arithmetic_check_div_34);
  tcase_add_test(tc_core, arithmetic_check_div_35);
  tcase_add_test(tc_core, arithmetic_check_div_36);
  tcase_add_test(tc_core, arithmetic_check_div_37);
  tcase_add_test(tc_core, arithmetic_check_div_38);
  tcase_add_test(tc_core, arithmetic_check_div_39);
  tcase_add_test(tc_core, arithmetic_check_div_40);
  tcase_add_test(tc_core, arithmetic_check_div_41);

  return s;
}