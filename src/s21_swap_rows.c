#include "s21_matrix.h"

void swap_rows(matrix_t *A, int row, int *swap_value) {
  double tmp = 0;
  int row_to_swap = 0, stop = 0;

  for (int i = row; i < A->rows || stop == 0; i++) {
    if (stop != 1 && A->matrix[i][row] != 0) {
      row_to_swap = i;
      stop = 1;
    }
  }
  for (int i = 0; i < A->columns; i++) {
    tmp = A->matrix[row][i];
    A->matrix[row][i] = A->matrix[row_to_swap][i];
    A->matrix[row_to_swap][i] = tmp;
  }
  (*swap_value)++;
}
