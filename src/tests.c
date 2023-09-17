#include "tests.h"

#include <check.h>

int main() {
  int no_failed;
  SRunner *runner;

  runner = srunner_create(convert_int_suite());
  srunner_add_suite(runner, convert_float_suite());
  srunner_add_suite(runner, arithmetic_add_suite());
  srunner_add_suite(runner, arithmetic_sub_suite());
  srunner_add_suite(runner, arithmetic_mul_suite());
  srunner_add_suite(runner, arithmetic_div_suite());
  srunner_add_suite(runner, arithmetic_mod_suite());
  srunner_add_suite(runner, comparison_suite());
  srunner_add_suite(runner, additional_suite());

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return no_failed;
}