#include "s21_matrix.h"

void s21_change_matrix(matrix_t* det, int* swap_value) {
  for (int i = 0, n = 0; i < det->rows - 1 && n < det->columns; i++, n++) {
    if (det->matrix[i][n] == 0) {
      swap_rows(det, i, swap_value);
    }
    for (int b = i + 1; b < det->rows; b++) {
      double coefficient = det->matrix[b][i] / det->matrix[i][i];
      for (int j = i; j < det->columns; j++) {
        det->matrix[b][j] -= coefficient * det->matrix[i][j];
      }
    }
  }
}