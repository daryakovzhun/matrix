#ifndef SRC_S21_MATRIX
#define SRC_S21_MATRIX


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum  enum_error{
    OK,
    INCORRECT_MATRIX,
    ERROR_CAL
};

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
double s21_det(matrix_t *A);
void calc_minor(matrix_t *A, int i_remove, int j_remove, matrix_t* minor);

#endif  //  SRC_S21_MATRIX