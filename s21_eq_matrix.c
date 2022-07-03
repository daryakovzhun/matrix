#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int error = SUCCESS;
    if (!A || !B || A->rows != B->rows || A->columns != B->columns ||
        A->matrix == NULL || B->matrix == NULL) {
        return FAILURE;
    }

    for (int i = 0; error != FAILURE && i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-8) {
                error = FAILURE;
                break;
            }
        }
    }
    return error;
}
