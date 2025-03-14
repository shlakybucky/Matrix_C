#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite *s21_create_matrix_test();
Suite *s21_eq_matrix_test();
Suite *s21_sum_matrix_suite_test();
Suite *s21_sub_matrix_test();
Suite *s21_mult_number_test();
Suite *s21_mult_matrix_test();
Suite *s21_transpose_test();
Suite *s21_determinant_test();
Suite *s21_calc_complements_test();
Suite *s21_inverse_matrix_test();

#endif
