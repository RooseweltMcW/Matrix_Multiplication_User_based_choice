#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <direct.h>
#include <errno.h> //For EEXIST
#include <time.h> //For clock_t,clock() & CLOCKS_PER_SEC
#include <stdio.h>
#include <string.h> // for strcmp

void matrix_multiply_ijk(int **A, int **B, int **C, int row, int col) {
    // Initialize the result matrix to zero
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            C[i][j] = 0;
            for (int k = 0; k < row; k++) { // Iterate based on the shared dimension (assuming it matches row)
                printf("Multiplying A[%d][%d] = %d with B[%d][%d] = %d\n", 
                        i, k, A[i][k], k, j, B[k][j]);
                C[i][j] += A[i][k] * B[k][j];
            }
            printf("Result C[%d][%d] = %d\n", i, j, C[i][j]);
        }
    }
}



void matrix_multiply_ikj(int **A, int **B, int **C, int size) {
    // Initialize the result matrix to zero
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            for (int j = 0; j < size; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_jik(int **A, int **B, int **C, int size) {
    // Initialize the result matrix to zero
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_jki(int **A, int **B, int **C, int size) {
    // Initialize the result matrix to zero
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_kij(int **A, int **B, int **C, int size) {
    // Initialize the result matrix to zero
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_kji(int **A, int **B, int **C, int size) {
    // Initialize the result matrix to zero
    for (int k = 0; k < size; k++) {
        for (int j = 0; j < size; j++) {
            for (int i = 0; i < size; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int compare_matrix(int **A, int **B, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (A[i][j] != B[i][j]) {
                printf("Mismatch at [%d][%d]: Matrix 1 = %d, Matrix 2 = %d\n", i, j, A[i][j], B[i][j]);
                return 0;
            }
        }
    }
    printf("Both matrices are the same\n");
    return 1;
}

// Function to read a matrix from a file
void read_matrix(const char *filename, int **matrix, int row,int col) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
}

void log_test_result(const char *filename, const char *test_name, const char *start_time, const char *end_time, double time_spent) {
    FILE *report_file = fopen("report.csv", "a");  // Open in append mode
    if (report_file == NULL) {
        printf("Error opening report file for writing.\n");
        exit(1);
    }

    // Write a new row with test details
    fprintf(report_file, "\"%s\",\"%s\",\"%s\",\"%f\n", test_name, start_time, end_time, time_spent);

    fclose(report_file);
}