#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int error = OK;
    if (rows <= 0 || columns <= 0 || result == NULL) {
        error = INCORRECT_MATRIX;
    } else {
        result->rows = rows;
        result->columns = columns;

        result->matrix = (double**)malloc(result->rows * sizeof(double*));
        if (result->matrix != NULL) {
            for (int i = 0; i < result->rows; i++) {
                result->matrix[i] = malloc(result->columns * sizeof(double));
                if (result->matrix[i] == NULL) {
                    error = INCORRECT_MATRIX;
                    break;
                }
            }
        } else {
            error = INCORRECT_MATRIX;
        }
    }

    return error;
}
