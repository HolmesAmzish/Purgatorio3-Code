// File: snake-matrix.cpp
// Date: 2024.03.31
// Author: Nulla

#include <iostream>

using namespace std;

// Allocate the matrix with dynamic memory
int** initialMatrix(int n) {
    int **matrix = new int*[n];
    for (int i =0; i < n; ++i) {
        matrix[i] = new int[n]; // Allocate each row of the matrix
    }
    return matrix;
}

void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

void convertMatrix(int **matrix_a, int **matrix_b, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix_b[j][i] = matrix_a[i][j];
        }
    }
}

int main() {
    cout << "Enter the number n: ";
    int n; cin >> n;

    cout << "Enter the elements of matrix A:\n";
    int** matrix_a = initialMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix_a[i][j];
        }
    }

    int** matrix_b = initialMatrix(n);
    convertMatrix(matrix_a, matrix_b, n);

    cout << "Matrix A:\n";
    printMatrix(matrix_a, n);
    cout << "Matrix B:\n";
    printMatrix(matrix_b, n);

    return 0;
}