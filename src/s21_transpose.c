#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    return MISTAKEN_MATRIX;
  }
  if (s21_inf_or_nan_number(A)) {
    return CALC_ERROR;
  }
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}