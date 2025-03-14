#include "test.h"

START_TEST(mult_number_test1) {
  matrix_t m = {0};
  double number = 2.7878787;
  s21_create_matrix(3, 3, &m);
  ck_assert_int_eq(s21_mult_number(&m, number, NULL), MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_test2) {
  matrix_t m = {0}, res = {0}, clone = {0};
  double number = rand() % 100 + 1;
  ;
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &clone);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;
  for (int i = 0; i < clone.rows; i++) {
    for (int j = 0; j < clone.columns; j++) {
      clone.matrix[i][j] = m.matrix[i][j] * number;
    }
  }
  ck_assert_int_eq(s21_mult_number(&m, number, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &clone), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&clone);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_test3) {
  matrix_t m = {0}, res = {0}, clone = {0};
  double number = 3;
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &clone);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 2;
      clone.matrix[i][j] = m.matrix[i][j] * number;
    }
  }
  ck_assert_int_eq(s21_mult_number(&m, number, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &clone), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&clone);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_test4) {
  matrix_t m = {0}, res = {0};
  double number = 3;
  s21_create_matrix(3, 3, &m);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 0.0 / 0.0;
    }
  }
  ck_assert_int_eq(s21_mult_number(&m, number, &res), CALC_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_test5) {
  matrix_t m = {0}, res = {0};
  double number = 0.0 / 0.0;
  s21_create_matrix(3, 3, &m);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 5.76767;
    }
  }
  ck_assert_int_eq(s21_mult_number(&m, number, &res), CALC_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_test6) {
  matrix_t res = {0};
  double number = 1.56;
  ck_assert_int_eq(s21_mult_number(NULL, number, &res), MISTAKEN_MATRIX);
}
END_TEST

START_TEST(mult_number_test7) {
  matrix_t m = {0}, res = {0};
  double number = rand() % 100 + 1;
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(s21_mult_number(&m, number, &res), MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

Suite* s21_mult_number_test() {
  Suite* suite = suite_create("s21_mult_number");
  TCase* tCase = tcase_create("s21_mult_number_case");
  tcase_add_test(tCase, mult_number_test1);
  tcase_add_test(tCase, mult_number_test2);
  tcase_add_test(tCase, mult_number_test3);
  tcase_add_test(tCase, mult_number_test4);
  tcase_add_test(tCase, mult_number_test5);
  tcase_add_test(tCase, mult_number_test6);
  tcase_add_test(tCase, mult_number_test7);
  suite_add_tcase(suite, tCase);

  return suite;
}