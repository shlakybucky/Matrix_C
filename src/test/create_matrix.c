#include "test.h"

START_TEST(create_ok1_matrix) {
  int rows = 3, cols = 3;
  matrix_t m = {0};
  int res = s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq(0, m.matrix[i][j]);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_ok2_matrix) {
  int res = 10, rows = 7, cols = 70;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = i + j;
      ck_assert_ldouble_eq(i + j, m.matrix[i][j]);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_ok3_matrix) {
  int res = 10, rows = 1, cols = 100;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 5;
      ck_assert_ldouble_eq(5, m.matrix[i][j]);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_ok4_matrix) {
  int res = 10, rows = 100, cols = 1;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = j + 1;
      ck_assert_ldouble_eq(j + 1, m.matrix[i][j]);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_ok5_matrix) {
  int res = 10, rows = 3, cols = 3;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  ck_assert_ldouble_eq(2, m.matrix[0][0]);
  ck_assert_ldouble_eq(5, m.matrix[0][1]);
  ck_assert_ldouble_eq(7, m.matrix[0][2]);
  ck_assert_ldouble_eq(6, m.matrix[1][0]);
  ck_assert_ldouble_eq(3, m.matrix[1][1]);
  ck_assert_ldouble_eq(4, m.matrix[1][2]);
  ck_assert_ldouble_eq(5, m.matrix[2][0]);
  ck_assert_ldouble_eq(-2, m.matrix[2][1]);
  ck_assert_ldouble_eq(-3, m.matrix[2][2]);

  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_no_rows_matrix) {
  int rows = 0, cols = 15, res = 10;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(res, MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_no_cols_matrix) {
  int rows = 15, cols = 0, res = 10;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(res, MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_zero_matrix) {
  int rows = 0, cols = 0, res = 10;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(res, MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_null_matrix) {
  int rows = 1, cols = 1, res = 10;

  res = s21_create_matrix(rows, cols, NULL);
  ck_assert_int_eq(res, MISTAKEN_MATRIX);
}
END_TEST

START_TEST(create_negative_matrix) {
  int rows = -1, cols = -1, res = 10;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(res, MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_negative_row_matrix) {
  int rows = -1, cols = 1, res = 10;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(res, MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_negative_cols_matrix) {
  int rows = 1, cols = -1, res = 10;
  matrix_t m = {0};
  res = s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(res, MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

Suite* s21_create_matrix_test() {
  Suite* suite = suite_create("s21_create_matrix");
  TCase* tCase = tcase_create("s21_create_matrix_case");
  tcase_add_test(tCase, create_ok1_matrix);
  tcase_add_test(tCase, create_ok2_matrix);
  tcase_add_test(tCase, create_ok3_matrix);
  tcase_add_test(tCase, create_ok4_matrix);
  tcase_add_test(tCase, create_ok5_matrix);
  tcase_add_test(tCase, create_no_rows_matrix);
  tcase_add_test(tCase, create_no_cols_matrix);
  tcase_add_test(tCase, create_zero_matrix);
  tcase_add_test(tCase, create_null_matrix);
  tcase_add_test(tCase, create_negative_matrix);
  tcase_add_test(tCase, create_negative_row_matrix);
  tcase_add_test(tCase, create_negative_cols_matrix);
  suite_add_tcase(suite, tCase);

  return suite;
}
