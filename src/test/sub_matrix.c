#include "test.h"

START_TEST(sub_test1) {
  int rows = 5;
  int cols = 5;
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0}, clone = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &clone);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = j + 2;
      m1.matrix[i][j] = j + 1;
      clone.matrix[i][j] = m.matrix[i][j] - m1.matrix[i][j];
    }
  }

  check = s21_sub_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, OK);
  ck_assert_int_eq(s21_eq_matrix(&clone, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&clone);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_test2) {
  matrix_t A = {0};
  matrix_t B = {0};
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), MISTAKEN_MATRIX);
}
END_TEST

START_TEST(sub_test3) {
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(1, 1, &m1);
  check = s21_sub_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_test4) {
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &m1);
  m.rows = -1;
  check = s21_sub_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, MISTAKEN_MATRIX);
  m.rows = 3;
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_test5) {
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m1.rows; j++) {
      m.matrix[i][j] = j + 2;
      m1.matrix[i][j] = 0.0 / 0.0;
    }
  }
  check = s21_sub_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_test6) {
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m1.rows; j++) {
      m.matrix[i][j] = j + 2;
      m1.matrix[i][j] = 1.0 / 0.0;
    }
  }
  check = s21_sub_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_test7) {
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m1.rows; j++) {
      m.matrix[i][j] = j + 2;
      m1.matrix[i][j] = -1.0 / 0.0;
    }
  }
  check = s21_sub_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_test8) {
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0}, clone = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &clone);
  m1.matrix[0][0] = 2;
  m1.matrix[0][1] = 5;
  m1.matrix[0][2] = 7;
  m1.matrix[1][0] = 6;
  m1.matrix[1][1] = 3;
  m1.matrix[1][2] = 4;
  m1.matrix[2][0] = 5;
  m1.matrix[2][1] = -2;
  m1.matrix[2][2] = -3;
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m1.rows; j++) {
      m.matrix[i][j] = j + 2;
      clone.matrix[i][j] = m.matrix[i][j] - m1.matrix[i][j];
    }
  }

  check = s21_sub_matrix(&m, &m1, &res);
  ck_assert_int_eq(s21_eq_matrix(&clone, &res), SUCCESS);
  ck_assert_int_eq(check, OK);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&res);
  s21_remove_matrix(&clone);
}
END_TEST

Suite* s21_sub_matrix_test() {
  Suite* suite = suite_create("s21_sub_matrix");
  TCase* tCase = tcase_create("s21_sub_matrix_case");
  tcase_add_test(tCase, sub_test1);
  tcase_add_test(tCase, sub_test2);
  tcase_add_test(tCase, sub_test3);
  tcase_add_test(tCase, sub_test4);
  tcase_add_test(tCase, sub_test5);
  tcase_add_test(tCase, sub_test6);
  tcase_add_test(tCase, sub_test7);
  tcase_add_test(tCase, sub_test8);
  suite_add_tcase(suite, tCase);

  return suite;
}