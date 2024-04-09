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


int main() {
    int n; cin >> n;

    int** matrix_a = initialMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix_a[i][j];
        }
    }

    printMatrix(matrix_a, n);
    cout << "\n";

for (int col = 0; col < n; col++) {
    if (col % 2 == 0) {
        for (int row = 0; row < n; row++) {
            cout << matrix_a[row][col] << ' ';
        }
        cout << endl;
    } else {
        for (int row = n - 1; row >= 0; row--) { // Changed row > 0 to row >= 0
            cout << matrix_a[row][col] << ' ';
        }
        cout << endl;
    }
}


    return 0;
}