#include "s21_matrix.h"

int s21_minor(matrix_t* A, matrix_t* minor, int rows, int columns) {
  if (minor == NULL || A == NULL || minor->rows <= 0 || minor->columns <= 0) {
    return MISTAKEN_MATRIX;
  }
  if (s21_inf_or_nan_number(minor) || s21_inf_or_nan_number(A) ||
      minor->rows != minor->columns || A->rows != A->columns) {
    return CALC_ERROR;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i < rows && j < columns) {
        minor->matrix[i][j] = A->matrix[i][j];
      } else if (i > rows && j > columns) {
        minor->matrix[i - 1][j - 1] = A->matrix[i][j];
      } else if (i < rows && j > columns) {
        minor->matrix[i][j - 1] = A->matrix[i][j];
      } else if (i > rows && j < columns) {
        minor->matrix[i - 1][j] = A->matrix[i][j];
      }
    }
  }
  return OK;
}
