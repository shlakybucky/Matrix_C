#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->rows <= 0 ||
      A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    return MISTAKEN_MATRIX;
  }
  if (A->columns != B->columns || A->rows != B->rows ||
      s21_inf_or_nan_number(A) || s21_inf_or_nan_number(B)) {
    return CALC_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}
