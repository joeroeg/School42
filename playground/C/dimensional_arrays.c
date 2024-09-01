#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4
#define DEPTH 4


void static_2d_array() {
    // Declare a 2D array (matrix) with 3 rows and 4 columns
    int matrix[3][4];

    // Initialize the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = i * 4 + j;
        }
    }

    // Print the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void dynamic_2d_array() {
    // Allocate memory for a 2D array (matrix) with 3 rows and 4 columns
    int **matrix = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        matrix[i] = (int *)malloc(4 * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = i * 4 + j;
        }
    }

    // Print the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void static_3d_array() {
    // Declare a 3D array (matrix) with 3 rows, 4 columns, and 2 depth
    int matrix[ROWS][COLS][DEPTH];

    // Initialize the matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < DEPTH; k++) {
                matrix[i][j][k] = i * COLS * DEPTH + j * DEPTH + k;
            }
        }
    }

    // Print the matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < DEPTH; k++) {
                printf("%2d ", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

}

int main() {
    static_2d_array();
    printf("------------------\n");
    dynamic_2d_array();
    printf("------------------\n");
    static_3d_array();

    return 0;
}
