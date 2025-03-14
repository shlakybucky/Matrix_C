#include "test.h"

START_TEST(m_no_rows_matrix) {
  int rows = 1, cols = 15, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(0, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m1.matrix[i][j] = 0;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(m1_no_rows_matrix) {
  int rows = 1, cols = 15, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(0, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 0;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&m);
}
END_TEST

// MISTAKEN_MATRIX
START_TEST(m_no_cols_matrix) {
  int rows = 15, cols = 1, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, 0, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m1.matrix[i][j] = 0;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(m1_no_cols_matrix) {
  int rows = 15, cols = 1, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, 0, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 0;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(zero_matrix) {
  int rows = 0, cols = 0, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(null_matrix) {
  int res = 10;
  res = s21_eq_matrix(NULL, NULL);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(negative_matrix) {
  int rows = -1, cols = -1, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(negative_row_matrix) {
  int rows = 1, cols = 1, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 1.11111111;
      m1.matrix[i][j] = 1.11111111;
    }
  }
  m1.rows = -1;
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  m1.rows = 1;
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(negative_cols_matrix) {
  int rows = 1, cols = 1, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 1.11111111;
      m1.matrix[i][j] = 1.11111111;
    }
  }
  m1.columns = -1;
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  m1.columns = 1;
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(ok_matrix1) {
  int rows = 3, cols = 3, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 1.11111111;
      m1.matrix[i][j] = 1.11111111;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix1) {
  int rows = 3, cols = 3, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 1.11111111;
      m1.matrix[i][j] = 1.11111111;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix2) {
  int rows = 3, cols = 3, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 1.11111111;
    }
  }
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m1.matrix[i][j] = 1.22222222;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix3) {
  int rows = 3, cols = 3, rows1 = 3, cols1 = 6, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows1, cols1, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 1.11111111;
    }
  }
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = 1.111111145454;
    }
  }

  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix4) {
  int rows = 3, cols = 3, rows1 = 3, cols1 = 6, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows1, cols1, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = 1.1111111111111111;
    }
  }
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = 1.1111111111111111145454;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix5) {
  int rows = rand() % 100 + 1, cols = rand() % 100 + 1,
      rows1 = rand() % 100 + 1, cols1 = rand() % 100 + 1, res = 10;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows1, cols1, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = rand() % 100 + 1;
    }
  }
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = rand() % 100 + 1;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix6) {
  int rows = rand() % 100 + 1, cols = rand() % 100 + 1, res = 10,
      rand_val = rand() % 100 + 1;
  matrix_t m = {0}, m1 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m1);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = rand_val;
      m1.matrix[i][j] = rand_val;
    }
  }
  res = s21_eq_matrix(&m, &m1);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix7) {
  matrix_t m = {0}, m1 = {0};
  int rows = 55;
  int cols = 1;
  const int rows1 = 45;
  const int cols1 = 46;
  rows = -rows;
  cols = -cols;
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows1, cols1, &m1);
  ck_assert_int_eq(s21_eq_matrix(&m, &m1), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m1);
}
END_TEST

Suite* s21_eq_matrix_test() {
  Suite* suite = suite_create("s21_eq_matrix");
  TCase* tCase = tcase_create("s21_eq_matrix_case");
  tcase_add_test(tCase, m_no_rows_matrix);
  tcase_add_test(tCase, m1_no_rows_matrix);
  tcase_add_test(tCase, m_no_cols_matrix);
  tcase_add_test(tCase, m1_no_cols_matrix);
  tcase_add_test(tCase, zero_matrix);
  tcase_add_test(tCase, null_matrix);
  tcase_add_test(tCase, negative_matrix);
  tcase_add_test(tCase, negative_row_matrix);
  tcase_add_test(tCase, negative_cols_matrix);
  tcase_add_test(tCase, ok_matrix1);
  tcase_add_test(tCase, eq_matrix1);
  tcase_add_test(tCase, eq_matrix2);
  tcase_add_test(tCase, eq_matrix3);
  tcase_add_test(tCase, eq_matrix4);
  tcase_add_test(tCase, eq_matrix5);
  tcase_add_test(tCase, eq_matrix6);
  tcase_add_test(tCase, eq_matrix7);
  suite_add_tcase(suite, tCase);

  return suite;
}
