#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  *result = 1;
  int swap_value = 0;
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    return MISTAKEN_MATRIX;
  }
  if (s21_inf_or_nan_number(A) || A->rows != A->columns) {
    return CALC_ERROR;
  }
  matrix_t det = {0};
  s21_create_matrix(A->rows, A->columns, &det);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      det.matrix[i][j] = A->matrix[i][j];
    }
  }
  s21_change_matrix(&det, &swap_value);
  for (int i = 0, j = 0; i < det.rows && j < det.columns; i++, j++) {
    *result *= det.matrix[i][j];
  }
  *result *= pow(-1, swap_value);

  if (*result == -0) {
    *result = 0;
  }
  s21_remove_matrix(&det);
  return OK;
}
