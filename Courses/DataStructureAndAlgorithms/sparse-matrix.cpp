// File: sparse-matrix.cpp
// Date: 2024.04.07
// Author: Nulla

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct elementsInfo {
    int row, col, data;
};

class sparseMatrix {
    public:
    int rows, cols, non_zero_count;

    vector<elementsInfo> non_zero_table;

    void nonZeroElemAssign(int row, int col, int data) {
        non_zero_table.push_back({row, col, data});
    }

    void displayMatrix() {
        cout << "Parse matrix:\n";
        int index = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == non_zero_table[index].row && j == non_zero_table[index].col) {
                    cout << non_zero_table[index++].data << '\t';
                } else {
                    cout << "0\t";
                }
            }
            cout << '\n';
        }
        cout << endl;
    }

    void transposeMatrix() {
        for (int index = 0; index < non_zero_count; ++index) {
            swap(non_zero_table[index].row, non_zero_table[index].col);
        }
        // TODO: ???
        sort(non_zero_table.begin(), non_zero_table.end(), 
        [](const elementsInfo& a, const elementsInfo& b) {
            if (a.row != b.row) return a.row < b.row;
            return a.col < b.col;
        });
    }

    void displayFirstN0Element() {
        cout << "Table of first non zero element:\n";
        int current_row = -1;
        for (int index = 0; index < non_zero_count; ++index) {
            if (non_zero_table[index].row != current_row) {
                current_row = non_zero_table[index].row;
                cout << "Row " << current_row << ": Index " << index << '\n';
            }
        }
        cout << endl;
    }

    void displayN0Table() {
        cout << "Table of non zero elements:\n";
        for (int index = 0; index < non_zero_count; ++index) {
            cout << non_zero_table[index].row << ' ' << non_zero_table[index].col << ' ' << non_zero_table[index].data << '\n';
        }
        cout << endl;
    }
};

int main() {
    sparseMatrix matrix;
    cin >> matrix.rows >> matrix.cols >> matrix.non_zero_count;

    for (int i = 0; i < matrix.non_zero_count; i++) {
        int row, col, data;
        cin >> row >> col >> data;
        matrix.nonZeroElemAssign(row, col, data);
    }

    matrix.displayMatrix();
    matrix.transposeMatrix();
    matrix.displayFirstN0Element();
    matrix.displayN0Table();
    matrix.displayMatrix();

    return 0;
}