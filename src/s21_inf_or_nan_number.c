#include "s21_matrix.h"

int s21_inf_or_nan_number(matrix_t *matrix) {
  int check = OK;
  for (int i = 0; i < matrix->rows && !check; i++) {
    for (int j = 0; j < matrix->columns && !check; j++) {
      if (isinf(matrix->matrix[i][j]) || isnan(matrix->matrix[i][j])) {
        check = CALC_ERROR;
      }
    }
  }
  return check;
}