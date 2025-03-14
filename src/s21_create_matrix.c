#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows <= 0 || columns <= 0) {
    return MISTAKEN_MATRIX;
  }
  int check = OK;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
  } else {
    check = MISTAKEN_MATRIX;
  }
  result->rows = rows;
  result->columns = columns;
  return check;
}