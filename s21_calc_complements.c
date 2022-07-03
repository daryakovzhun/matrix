#include "s21_matrix.h"

void calc_minor(matrix_t *A, int i_remove, int j_remove, matrix_t* minor) {
    int k = 0, s;
    for (int i = 0; i < A->rows; i++) {
        if (i != i_remove) {
            s = 0;
            for (int j = 0; j < A->columns; j++) {
                if (j != j_remove) {
                    minor->matrix[k][s] = A->matrix[i][j];
                    s++;
                }
            }
            k++;
        }
    }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int error = OK;
    if (!A || A->matrix == NULL || A->columns != A->rows) {
        return ERROR_CAL;
    }

    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == OK) {
        matrix_t minor;
        error = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        if (error == OK) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    calc_minor(A, i, j, &minor);
                    result->matrix[i][j] = s21_det(&minor) * pow(-1, i + j);
                }
            }
            s21_remove_matrix(&minor);
        }
    }

    return error;
}
