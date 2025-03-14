#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    return MISTAKEN_MATRIX;
  }
  if (s21_inf_or_nan_number(A) || A->rows != A->columns) {
    return CALC_ERROR;
  }

  matrix_t minor = {0};
  double res = 0;

  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1 && A->columns == 1)
    result->matrix[0][0] = A->matrix[0][0];
  else {
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_minor(A, &minor, i, j);
        s21_determinant(&minor, &res);
        result->matrix[i][j] = res * pow(-1, (i + j));
      }
    }
  }
  s21_remove_matrix(&minor);
  return OK;
}
