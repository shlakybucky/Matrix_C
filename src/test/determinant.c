#include "test.h"

START_TEST(determinant_test1) {
  matrix_t m = {0};
  double det = 0;
  ck_assert_int_eq(s21_determinant(&m, &det), MISTAKEN_MATRIX);
}
END_TEST

START_TEST(determinant_test2) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(1, 2, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  ck_assert_int_eq(s21_determinant(&m, &det), CALC_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test3) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(3, 3, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 4;
  m.matrix[1][1] = 5;
  m.matrix[1][2] = 6;
  m.matrix[2][0] = 7;
  m.matrix[2][1] = 8;
  m.matrix[2][2] = 9;
  ck_assert_int_eq(s21_determinant(&m, &det), OK);
  ck_assert_int_eq(det, 0);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test4) {
  const int cells = 5;
  double res = 0;
  matrix_t m = {0};
  int check = 10;
  s21_create_matrix(cells, cells, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  check = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-3);
  ck_assert_int_eq(check, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test5) {
  matrix_t m = {0};
  double det = 0;
  int check = 10;
  s21_create_matrix(3, 3, &m);  // -40
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;
  check = s21_determinant(&m, &det);
  ck_assert_int_eq(check, OK);
  ck_assert_double_eq(det, -40);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test6) {
  const int cells = 3;
  matrix_t m = {0};
  double det = 0;
  int check = 10;
  s21_create_matrix(cells, cells, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;
  check = s21_determinant(&m, &det);
  ck_assert_double_eq_tol(det, -32, 1e-6);
  ck_assert_int_eq(check, 0);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test7) {
  const int cells = 2;
  matrix_t m = {0};
  double det = 0;

  s21_create_matrix(cells, cells, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;
  int check = s21_determinant(&m, &det);
  ck_assert_double_eq_tol(det, 7, 1e-6);
  ck_assert_int_eq(check, 0);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test8) {
  matrix_t m = {0};
  double det = 0;
  int rows = rand() % 100 + 1, check = 10;
  rows = -rows;
  s21_create_matrix(rows, rows, &m);
  check = s21_determinant(&m, &det);
  ck_assert_int_eq(check, MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test9) {
  matrix_t m = {0};
  int rows = 4, cols = 5, check = 10;
  double det = 0;
  s21_create_matrix(rows, cols, &m);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 56;
    }
  }
  check = s21_determinant(&m, &det);
  ck_assert_int_eq(check, CALC_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

Suite* s21_determinant_test() {
  Suite* suite = suite_create("s21_determinant");
  TCase* tCase = tcase_create("s21_determinant_case");
  tcase_add_test(tCase, determinant_test1);
  tcase_add_test(tCase, determinant_test2);
  tcase_add_test(tCase, determinant_test3);
  tcase_add_test(tCase, determinant_test4);
  tcase_add_test(tCase, determinant_test5);
  tcase_add_test(tCase, determinant_test6);
  tcase_add_test(tCase, determinant_test7);
  tcase_add_test(tCase, determinant_test8);
  tcase_add_test(tCase, determinant_test9);
  suite_add_tcase(suite, tCase);

  return suite;
}