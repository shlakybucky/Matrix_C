#include "test.h"

START_TEST(calc_test1) {
  matrix_t m = {0}, res = {0};
  s21_create_matrix(1, 1, &m);
  m.matrix[0][0] = 1;

  ck_assert_int_eq(s21_calc_complements(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &m), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_test2) {
  matrix_t m = {0}, res = {0};
  int check = 10;
  s21_create_matrix(1, 2, &m);
  check = s21_calc_complements(&m, &res);
  ck_assert_int_eq(check, CALC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_test3) {
  matrix_t m = {0};
  int check = 10;
  s21_create_matrix(1, 2, &m);
  check = s21_calc_complements(&m, NULL);
  ck_assert_int_eq(check, MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(calc_test4) {
  matrix_t m = {0}, clone = {0}, res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &clone);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;
  clone.matrix[0][0] = 0;
  clone.matrix[0][1] = 10;
  clone.matrix[0][2] = -20;
  clone.matrix[1][0] = 4;
  clone.matrix[1][1] = -14;
  clone.matrix[1][2] = 8;
  clone.matrix[2][0] = -8;
  clone.matrix[2][1] = -2, clone.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &clone), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&clone);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_test5) {
  matrix_t m = {0}, clone = {0}, res = {0};
  int check1 = s21_create_matrix(3, 3, &m);
  int check2 = s21_create_matrix(3, 3, &clone);
  int check3 = 10;
  if (check1 == 0 && check2 == 0) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;
    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;
    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    clone.matrix[0][0] = 0;
    clone.matrix[0][1] = 10;
    clone.matrix[0][2] = -20;
    clone.matrix[1][0] = 4;
    clone.matrix[1][1] = -14;
    clone.matrix[1][2] = 8;
    clone.matrix[2][0] = -8;
    clone.matrix[2][1] = -2;
    clone.matrix[2][2] = 4;

    check3 = s21_calc_complements(&m, &res);

    ck_assert_int_eq(s21_eq_matrix(&res, &clone), SUCCESS);
    ck_assert_int_eq(check3, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&res);
    s21_remove_matrix(&clone);
  }
}
END_TEST

START_TEST(calc_test6) {
  matrix_t m = {0}, res = {0}, clone = {0};
  int check = 10;
  s21_create_matrix(5, 5, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[0][3] = 4;
  m.matrix[0][4] = 5;
  m.matrix[1][0] = 3;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[1][3] = 3;
  m.matrix[1][4] = 1;
  m.matrix[2][0] = 2;
  m.matrix[2][1] = 4;
  m.matrix[2][2] = 5;
  m.matrix[2][3] = 2;
  m.matrix[2][4] = 2;
  m.matrix[3][0] = 4;
  m.matrix[3][1] = 1;
  m.matrix[3][2] = 2;
  m.matrix[3][3] = 1;
  m.matrix[3][4] = 3;
  m.matrix[4][0] = 5;
  m.matrix[4][1] = 5;
  m.matrix[4][2] = 1;
  m.matrix[4][3] = 5;
  m.matrix[4][4] = 4;

  s21_create_matrix(5, 5, &clone);
  clone.matrix[0][0] = 100;
  clone.matrix[0][1] = 117;
  clone.matrix[0][2] = -42;
  clone.matrix[0][3] = -127;
  clone.matrix[0][4] = -102;
  clone.matrix[1][0] = -110;
  clone.matrix[1][1] = 252;
  clone.matrix[1][2] = -132;
  clone.matrix[1][3] = -322;
  clone.matrix[1][4] = 258;
  clone.matrix[2][0] = 100;
  clone.matrix[2][1] = -288;
  clone.matrix[2][2] = -42;
  clone.matrix[2][3] = 278;
  clone.matrix[2][4] = -102;
  clone.matrix[3][0] = -170;
  clone.matrix[3][1] = 117;
  clone.matrix[3][2] = -42;
  clone.matrix[3][3] = 143;
  clone.matrix[3][4] = -102;
  clone.matrix[4][0] = -20;
  clone.matrix[4][1] = -153;
  clone.matrix[4][2] = 138;
  clone.matrix[4][3] = -7;
  clone.matrix[4][4] = -12;

  check = s21_calc_complements(&m, &res);
  ck_assert_int_eq(check, OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &clone), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&clone);
}
END_TEST

Suite* s21_calc_complements_test() {
  Suite* suite = suite_create("s21_calc_complements");
  TCase* tCase = tcase_create("s21_calc_complements_case");
  tcase_add_test(tCase, calc_test1);
  tcase_add_test(tCase, calc_test2);
  tcase_add_test(tCase, calc_test3);
  tcase_add_test(tCase, calc_test4);
  tcase_add_test(tCase, calc_test5);
  tcase_add_test(tCase, calc_test6);
  suite_add_tcase(suite, tCase);

  return suite;
}