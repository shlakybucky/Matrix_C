#include "test.h"

START_TEST(inverse_test1) {
  matrix_t res = {0};

  ck_assert_int_eq(s21_inverse_matrix(NULL, &res), MISTAKEN_MATRIX);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_test2) {
  matrix_t m = {0};
  s21_create_matrix(4, 4, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[0][3] = 0;
  m.matrix[1][0] = 4;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 2;
  m.matrix[1][3] = 5;
  m.matrix[2][0] = 6;
  m.matrix[2][1] = 7;
  m.matrix[2][2] = 8;
  m.matrix[2][3] = 9;
  m.matrix[3][0] = 3;
  m.matrix[3][1] = 2;
  m.matrix[3][2] = 1;
  m.matrix[3][3] = 9;
  ck_assert_int_eq(s21_inverse_matrix(&m, NULL), MISTAKEN_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_test3) {
  matrix_t m = {0}, res = {0};
  s21_create_matrix(5, 3, &m);
  ck_assert_int_eq(s21_inverse_matrix(&m, &res), CALC_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_test4) {
  matrix_t m = {0}, result = {0}, expected = {0};
  int size = 8;
  s21_create_matrix(size, size, &m);
  s21_create_matrix(size, size, &expected);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 8;
  m.matrix[0][2] = 7;
  m.matrix[0][3] = 4;
  m.matrix[0][4] = 1;
  m.matrix[0][5] = 8;
  m.matrix[0][6] = 3;
  m.matrix[0][7] = 9;

  m.matrix[1][0] = 4;
  m.matrix[1][1] = 2;
  m.matrix[1][2] = 6;
  m.matrix[1][3] = 2;
  m.matrix[1][4] = 2;
  m.matrix[1][5] = 1;
  m.matrix[1][6] = 5;
  m.matrix[1][7] = 8;

  m.matrix[2][0] = 8;
  m.matrix[2][1] = 6;
  m.matrix[2][2] = 7;
  m.matrix[2][3] = 7;
  m.matrix[2][4] = 3;
  m.matrix[2][5] = 4;
  m.matrix[2][6] = 4;
  m.matrix[2][7] = 1;

  m.matrix[3][0] = 1;
  m.matrix[3][1] = 7;
  m.matrix[3][2] = 0;
  m.matrix[3][3] = 4;
  m.matrix[3][4] = 4;
  m.matrix[3][5] = 3;
  m.matrix[3][6] = 0;
  m.matrix[3][7] = 5;

  m.matrix[4][0] = 5;
  m.matrix[4][1] = 7;
  m.matrix[4][2] = 5;
  m.matrix[4][3] = 6;
  m.matrix[4][4] = 8;
  m.matrix[4][5] = 3;
  m.matrix[4][6] = 1;
  m.matrix[4][7] = 9;

  m.matrix[5][0] = 3;
  m.matrix[5][1] = 7;
  m.matrix[5][2] = 8;
  m.matrix[5][3] = 0;
  m.matrix[5][4] = 5;
  m.matrix[5][5] = 7;
  m.matrix[5][6] = 0;
  m.matrix[5][7] = 2;

  m.matrix[6][0] = 5;
  m.matrix[6][1] = 8;
  m.matrix[6][2] = 3;
  m.matrix[6][3] = 5;
  m.matrix[6][4] = 9;
  m.matrix[6][5] = 1;
  m.matrix[6][6] = 2;
  m.matrix[6][7] = 0;

  m.matrix[7][0] = 7;
  m.matrix[7][1] = 8;
  m.matrix[7][2] = 7;
  m.matrix[7][3] = 4;
  m.matrix[7][4] = 7;
  m.matrix[7][5] = 9;
  m.matrix[7][6] = 1;
  m.matrix[7][7] = 5;

  expected.matrix[0][0] = -0.5349902183;
  expected.matrix[0][1] = 0.2894503762;
  expected.matrix[0][2] = 0.2648128502;
  expected.matrix[0][3] = 0.6295578936;
  expected.matrix[0][4] = -0.1684575429;
  expected.matrix[0][5] = 0.2471263249;
  expected.matrix[0][6] = -0.3773947292;
  expected.matrix[0][7] = 0.0217143747;

  expected.matrix[1][0] = -0.3358379646;
  expected.matrix[1][1] = 0.2037511071;
  expected.matrix[1][2] = 0.2032547229;
  expected.matrix[1][3] = 0.6234293334;
  expected.matrix[1][4] = -0.1799149334;
  expected.matrix[1][5] = 0.3295114996;
  expected.matrix[1][6] = -0.2254070837;
  expected.matrix[1][7] = -0.1935314328;

  expected.matrix[2][0] = 0.09452225456;
  expected.matrix[2][1] = -0.09221066155;
  expected.matrix[2][2] = 0.03813722914;
  expected.matrix[2][3] = -0.2190871073;
  expected.matrix[2][4] = 0.1695573745;
  expected.matrix[2][5] = 0.1092580516;
  expected.matrix[2][6] = 0.007715043036;
  expected.matrix[2][7] = -0.1600498331;

  expected.matrix[3][0] = 0.3630563639;
  expected.matrix[3][1] = -0.3052665388;
  expected.matrix[3][2] = -0.04656927155;
  expected.matrix[3][3] = -0.4771776828;
  expected.matrix[3][4] = 0.2389343637;
  expected.matrix[3][5] = -0.2685487089;
  expected.matrix[3][6] = 0.1928760759;
  expected.matrix[3][7] = -0.001245826966;

  expected.matrix[4][0] = 0.2619837848;
  expected.matrix[4][1] = -0.133556544;
  expected.matrix[4][2] = -0.2495968906;
  expected.matrix[4][3] = -0.4562289726;
  expected.matrix[4][4] = 0.1044612934;
  expected.matrix[4][5] = -0.2245895097;
  expected.matrix[4][6] = 0.3128420752;
  expected.matrix[4][7] = 0.1500734843;

  expected.matrix[5][0] = 0.2992174649;
  expected.matrix[5][1] = -0.1560300945;
  expected.matrix[5][2] = -0.1850280149;
  expected.matrix[5][3] = -0.3646314915;
  expected.matrix[5][4] = -0.02339656554;
  expected.matrix[5][5] = -0.2701059926;
  expected.matrix[5][6] = 0.1915783395;
  expected.matrix[5][7] = 0.2628500238;

  expected.matrix[6][0] = 0.3028673486;
  expected.matrix[6][1] = 0.0418714657;
  expected.matrix[6][2] = -0.2001336669;
  expected.matrix[6][3] = -0.3106910771;
  expected.matrix[6][4] = -0.1692459178;
  expected.matrix[6][5] = -0.2826713255;
  expected.matrix[6][6] = 0.3477738954;
  expected.matrix[6][7] = 0.1562734201;

  expected.matrix[7][0] = -0.1023914038;
  expected.matrix[7][1] = 0.1015348978;
  expected.matrix[7][2] = 0.0104305565;
  expected.matrix[7][3] = 0.1667915738;
  expected.matrix[7][4] = 0.02489382894;
  expected.matrix[7][5] = 0.04583280613;
  expected.matrix[7][6] = -0.1284726616;
  expected.matrix[7][7] = -0.01017100922;

  ck_assert_int_eq(s21_inverse_matrix(&m, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite* s21_inverse_matrix_test() {
  Suite* suite = suite_create("s21_inverse_matrix()");
  TCase* tCase = tcase_create("s21_inverse_matrix()_case");
  tcase_add_test(tCase, inverse_test1);
  tcase_add_test(tCase, inverse_test2);
  tcase_add_test(tCase, inverse_test3);
  tcase_add_test(tCase, inverse_test4);
  suite_add_tcase(suite, tCase);

  return suite;
}