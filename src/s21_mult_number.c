#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    return MISTAKEN_MATRIX;
  }
  if (isnan(number) || isinf(number) || s21_inf_or_nan_number(A)) {
    return CALC_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}