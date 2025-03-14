#include "test.h"

START_TEST(mult_matrix_test1) {
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &m1);
  ck_assert_int_eq(s21_mult_matrix(&m, &m1, NULL), MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(mult_matrix_test2) {
  matrix_t m = {0};
  s21_create_matrix(3, 3, &m);
  ck_assert_int_eq(s21_mult_matrix(&m, NULL, NULL), MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_matrix_test3) {
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(4, 4, &m1);
  ck_assert_int_eq(s21_mult_matrix(&m, &m1, &res), CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_test4) {
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(3, 4, &m);
  s21_create_matrix(3, 4, &m1);
  ck_assert_int_eq(s21_mult_matrix(&m, &m1, &res), CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(mult_matrix_test5) {
  matrix_t m = {0}, m1 = {0}, res = {0}, clone = {0};
  int rand_v = rand() % 100 + 1;
  s21_create_matrix(3, 4, &m);
  s21_create_matrix(4, 3, &m1);
  s21_create_matrix(3, 3, &clone);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = rand_v;
    }
  }
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = rand_v;
    }
  }
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      clone.matrix[i][j] = 0;
      for (int k = 0; k < m.columns; k++) {
        clone.matrix[i][j] += m.matrix[i][k] * m1.matrix[k][j];
      }
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&m, &m1, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&clone, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&clone);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_test6) {
  matrix_t m = {0}, m1 = {0}, clone = {0}, res = {0};
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &m1);
  s21_create_matrix(m.rows, m1.columns, &clone);
  ck_assert_int_eq(s21_mult_matrix(&m, &m1, &res), MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&res);
  s21_remove_matrix(&clone);
}
END_TEST

Suite* s21_mult_matrix_test() {
  Suite* suite = suite_create("s21_mult_matrix");
  TCase* tCase = tcase_create("s21_mult_matrix_case");
  tcase_add_test(tCase, mult_matrix_test1);
  tcase_add_test(tCase, mult_matrix_test2);
  tcase_add_test(tCase, mult_matrix_test3);
  tcase_add_test(tCase, mult_matrix_test4);
  tcase_add_test(tCase, mult_matrix_test5);
  tcase_add_test(tCase, mult_matrix_test6);
  suite_add_tcase(suite, tCase);

  return suite;
}