#include "s21_matrix.h"

double s21_det(matrix_t *A) {
    double det = 0;

    if (A->rows == 1) {
        det = A->matrix[0][0];
    } else  if (A->rows == 2) {
        det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
        matrix_t minor;
        int error = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        if (error == OK) {
            int k = 1;
            for (int i = 0; i < A->rows; i++) {
                calc_minor(A, i, 0, &minor);
                det += k * A->matrix[i][0] * s21_det(&minor);
                k *= -1;
            }
        }
        s21_remove_matrix(&minor);
    }

    return det;
}

int s21_determinant(matrix_t *A, double *result) {
    int error = OK;
    if (!A || A->matrix == NULL || A->columns != A->rows) {
        return ERROR_CAL;
    }

    *result = s21_det(A);

    return error;
}
