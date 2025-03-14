#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->columns > 0 && A->rows > 0) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
  }
  A->columns = 0;
  A->rows = 0;
}