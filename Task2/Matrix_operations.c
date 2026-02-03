#include <stdio.h>

// Function prototypes
void inputMatrix(int mat[10][10], int rows, int cols);
void displayMatrix(int mat[10][10], int rows, int cols);
void addMatrices(int a[10][10], int b[10][10], int res[10][10], int r, int c);
void transposeMatrix(int mat[10][10], int res[10][10], int r, int c);
void multiplyMatrices(int a[10][10], int b[10][10], int res[10][10], int r1, int c1, int c2);

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;

    // 1. Input dimensions for Matrix A
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements for Matrix A:\n");
    inputMatrix(a, r1, c1);

    // 2. Input dimensions for Matrix B
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements for Matrix B:\n");
    inputMatrix(b, r2, c2);

    // --- Matrix Addition ---
    if (r1 == r2 && c1 == c2) {
        addMatrices(a, b, result, r1, c1);
        printf("\nResult of Addition:\n");
        displayMatrix(result, r1, c1);
    } else {
        printf("\nAddition not possible (Dimensions must match).\n");
    }

    // --- Matrix Transpose (of Matrix A) ---
    transposeMatrix(a, result, r1, c1);
    printf("\nTranspose of Matrix A:\n");
    displayMatrix(result, c1, r1); // Note: Rows and Cols are swapped

    // --- Matrix Multiplication ---
    if (c1 == r2) {
        multiplyMatrices(a, b, result, r1, c1, c2);
        printf("\nResult of Multiplication:\n");
        displayMatrix(result, r1, c2);
    } else {
        printf("\nMultiplication not possible (Col A must equal Row B).\n");
    }

    return 0;
}

// Function to take user input for matrix elements
void inputMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to print a matrix to the console
void displayMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Logic for Addition
void addMatrices(int a[10][10], int b[10][10], int res[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Logic for Transpose
void transposeMatrix(int mat[10][10], int res[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[j][i] = mat[i][j]; // Swap indices
        }
    }
}

// Logic for Multiplication
void multiplyMatrices(int a[10][10], int b[10][10], int res[10][10], int r1, int c1, int c2) {
    // Initialize result matrix with zeros
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
