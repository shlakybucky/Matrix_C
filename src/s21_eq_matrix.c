#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || A->columns != B->columns ||
      A->rows != B->rows || A->rows <= 0 || A->columns <= 0 || B->rows <= 0 ||
      B->columns <= 0) {
    return FAILURE;
  }
  int check = SUCCESS;
  for (int i = 0; i < A->rows && check != FAILURE; i++) {
    for (int j = 0; j < A->columns && check != FAILURE; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) < ACCURANCE) {
        check = SUCCESS;
      } else
        check = FAILURE;
    }
  }
  return check;
}