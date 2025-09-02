#include <stdio.h>

#define ROWS 3
#define COLS 3

void double_matrix_with_pointer(int* matrix, int rows, int cols);

// Function that uses a pointer to modify the matrix
void double_matrix_with_pointer(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows * cols; i++) {
        *(matrix + i) *= 2;
        printf("Element %d = %d, address = %p\n", i, *(matrix + i), (matrix + i));
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Element [%d][%d] = %d, address = %p\n", i, j, matrix[i][j], &matrix[i][j]);
        }
    }

    printf("\nModifying matrix using pointer...\n\n");
    double_matrix_with_pointer(&matrix[0][0], ROWS, COLS);

    printf("\nModified matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Element [%d][%d] = %d, address = %p\n", i, j, matrix[i][j], &matrix[i][j]);
        }
    }

    return 0;
}
