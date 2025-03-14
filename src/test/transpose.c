#include "test.h"

START_TEST(transpose_test1) {
  matrix_t m = {0}, res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), MISTAKEN_MATRIX);
}
END_TEST

START_TEST(transpose_test2) {
  int rows = 3, cols = 3;
  matrix_t m = {0}, clone = {0}, res = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &clone);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = i + j;
      clone.matrix[j][i] = i + j;
    }
  }
  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&clone, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&clone);
}
END_TEST

START_TEST(transpose_test3) {
  matrix_t m = {0}, res = {0};
  m.rows = 0;
  ck_assert_int_eq(s21_transpose(&m, &res), MISTAKEN_MATRIX);
}
END_TEST

START_TEST(transpose_test4) {
  matrix_t m = {0}, res = {0}, clone = {0};
  s21_create_matrix(2, 3, &m);
  s21_create_matrix(3, 2, &clone);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 4;
  m.matrix[1][1] = 5;
  m.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  clone.matrix[0][0] = 1;
  clone.matrix[0][1] = 4;
  clone.matrix[1][0] = 2;
  clone.matrix[1][1] = 5;
  clone.matrix[2][0] = 3;
  clone.matrix[2][1] = 6;
  ck_assert_int_eq(s21_eq_matrix(&res, &clone), SUCCESS);
  ck_assert_int_eq(res.rows, 3);
  ck_assert_int_eq(res.columns, 2);
  s21_remove_matrix(&m);
  s21_remove_matrix(&clone);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_test5) {
  int rows = 3, cols = 3;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = i + j;
    }
  }
  ck_assert_int_eq(s21_transpose(&m, NULL), MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

Suite* s21_transpose_test() {
  Suite* suite = suite_create("s21_s21_transpose");
  TCase* tCase = tcase_create("s21_s21_transpose_case");
  tcase_add_test(tCase, transpose_test1);
  tcase_add_test(tCase, transpose_test2);
  tcase_add_test(tCase, transpose_test3);
  tcase_add_test(tCase, transpose_test4);
  tcase_add_test(tCase, transpose_test5);
  suite_add_tcase(suite, tCase);

  return suite;
}