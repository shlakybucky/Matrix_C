#include "test.h"

int main() {
  int fail = 0;
  Suite* s21_matrix_test[] = {s21_create_matrix_test(),
                              s21_eq_matrix_test(),
                              s21_sum_matrix_suite_test(),
                              s21_sub_matrix_test(),
                              s21_mult_number_test(),
                              s21_mult_matrix_test(),
                              s21_transpose_test(),
                              s21_determinant_test(),
                              s21_calc_complements_test(),
                              s21_inverse_matrix_test(),
                              NULL};

  for (int i = 0; s21_matrix_test[i] != NULL; i++) {
    SRunner* sr = srunner_create(s21_matrix_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    fail += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  if (fail == 0) {
    printf("\n\033[32m      SUCCESFULLY FINISHED \033[0m\n\n");
  } else {
    printf("\033[31m      FAILED: %d\033[0m\n\n", fail);
  }
  return (fail == 0) ? fail : 1;
}