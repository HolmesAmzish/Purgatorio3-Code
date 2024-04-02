// File: snake-matrix.cpp
// Date: 2024.03.31
// Author: Nulla

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void printArray(const vector<int>& array, int n) {
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << array[index] << ' ';
            index++;
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> snakeMatrix(const vector<vector<int>>& matrix) {
    vector<int> result;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                result.push_back(matrix[i][j]);
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                result.push_back(matrix[i][j]);
            }
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix A:" << endl;
    printMatrix(matrix);

    vector<int> arrayB = snakeMatrix(matrix);
    cout << "\nArray B:" << endl;
    printArray(arrayB, n);

    return 0;
}
