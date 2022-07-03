#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int error = OK;
    double det = s21_det(A);
    if (!A || !result || A->matrix == NULL || A->columns != A->rows || fabs(det) <= 1e-7) {
        return ERROR_CAL;
    }

    matrix_t complement;
    error = s21_calc_complements(A, &complement);
    if (error == OK) {
        s21_transpose(&complement, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] /= det;
            }
        }
        s21_remove_matrix(&complement);
    }

    return error;
}
