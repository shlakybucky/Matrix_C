#include "test.h"

START_TEST(sum_test1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0}, clone = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &clone);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = j + 1;
      m1.matrix[i][j] = j + 1;
      clone.matrix[i][j] = m.matrix[i][j] + m1.matrix[i][j];
    }
  }
  check = s21_sum_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, OK);
  ck_assert_int_eq(s21_eq_matrix(&clone, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&clone);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_test2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 0.0 / 0.0;
      m1.matrix[i][j] = j + 1;
    }
  }
  check = s21_sum_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, CALC_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_test3) {
  matrix_t m = {0}, m1 = {0};
  int check = s21_sum_matrix(&m, &m1, NULL);
  ck_assert_int_eq(check, MISTAKEN_MATRIX);
}
END_TEST

START_TEST(sum_test4) {
  matrix_t m = {0}, m1 = {0}, res = {0};
  int check = 10;
  s21_create_matrix(10, 10, &m);
  s21_create_matrix(5, 5, &m1);
  check = s21_sum_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_test5) {
  matrix_t m = {0}, m1 = {0}, res = {0};
  int check = 10;
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 10;
      m1.matrix[i][j] = 10;
    }
  }
  check = s21_sum_matrix(&m, &m1, &res);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      ck_assert_int_eq(res.matrix[i][j], 20);
    }
  }
  ck_assert_int_eq(check, OK);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_test6) {
  matrix_t m = {0}, m1 = {0}, res = {0};
  int check = 10, rand_v = rand() % 100 + 1;
  ;
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows1, cols1, &m1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = rand_v;
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      m1.matrix[i][j] = rand_v;
    }
  }
  check = s21_sum_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_test7) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  int check = 10;
  matrix_t m = {0}, m1 = {0}, res = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = j + 1;
      m1.matrix[i][j] = j + 1;
    }
  }
  m.rows = -1;
  m1.rows = -1;
  check = s21_sum_matrix(&m, &m1, &res);
  ck_assert_int_eq(check, MISTAKEN_MATRIX);

  m.rows = rows;
  m1.rows = rows;
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

Suite* s21_sum_matrix_suite_test() {
  Suite* suite = suite_create("s21_sum_matrix");
  TCase* tCase = tcase_create("s21_sum_matrix_case");
  tcase_add_test(tCase, sum_test1);
  tcase_add_test(tCase, sum_test2);
  tcase_add_test(tCase, sum_test3);
  tcase_add_test(tCase, sum_test4);
  tcase_add_test(tCase, sum_test5);
  tcase_add_test(tCase, sum_test6);
  tcase_add_test(tCase, sum_test7);
  suite_add_tcase(suite, tCase);

  return suite;
}