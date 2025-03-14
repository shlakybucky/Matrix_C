#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!A || !result) {
    return MISTAKEN_MATRIX;
  }
  if (A->rows <= 0 || A->columns <= 0) {
    return MISTAKEN_MATRIX;
  } else if (s21_inf_or_nan_number(A) || A->rows != A->columns) {
    return CALC_ERROR;
  }

  int check = OK;
  double det = 1;
  s21_determinant(A, &det);
  if (det == 0) {
    check = CALC_ERROR;
  } else {
    matrix_t complements = {0}, transpose = {0};
    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose);
    s21_mult_number(&transpose, 1 / det, result);
    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose);
  }
  return check;
}