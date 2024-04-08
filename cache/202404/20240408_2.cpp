#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to construct a symmetric matrix from lower triangle data
vector<vector<int>> constructSymmetricMatrix(const vector<int>& lowerTriangleData) {
    // Calculate the size of the square matrix
    int n = static_cast<int>(sqrt(2 * lowerTriangleData.size() + 0.25) - 0.5);

    // Initialize the symmetric matrix with zeros
    vector<vector<int>> symmetricMatrix(n, vector<int>(n, 0));

    // Populate the symmetric matrix from lower triangle data
    int index = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = j; i < n; ++i) {
            symmetricMatrix[i][j] = lowerTriangleData[index];
            symmetricMatrix[j][i] = lowerTriangleData[index];
            ++index;
        }
    }

    return symmetricMatrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> multiplyMatrix(vector<vector<int>> matrix_1, vector<vector<int>> matrix_2) {
    vector<vector<int>> matrix_result;
    
    // 获取矩阵的行数和列数
    int rows1 = matrix_1.size();
    int cols1 = matrix_1[0].size();
    int rows2 = matrix_2.size();
    int cols2 = matrix_2[0].size();

    // 检查两个矩阵是否可以相乘
    if (cols1 != rows2) {
        cerr << "Error: Matrix dimensions are not compatible for multiplication." << endl;
        return {};
    }

    // 初始化结果矩阵为全零矩阵
    matrix_result.resize(rows1, vector<int>(cols2, 0));

    // 实现矩阵乘法
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                matrix_result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    
    return matrix_result;
}

int main() {
    vector<int> array_1, array_2;
    int temp;
    while (cin >> temp, temp != -1) {
        array_1.push_back(temp);
    }
    while (cin >> temp, temp != -1) {
        array_2.push_back(temp);
    }

    if (array_1.size() != array_2.size()) {
        cout << "error\n";
        exit(EXIT_FAILURE);
    }

    // Construct symmetric matrix
    vector<vector<int>> symmetric_matrix_1 = constructSymmetricMatrix(array_1);
    vector<vector<int>> symmetric_matrix_2 = constructSymmetricMatrix(array_2);

    vector<vector<int>> result = multiplyMatrix(symmetric_matrix_1, symmetric_matrix_2);
    // Print the constructed symmetric matrix
    //printMatrix(symmetric_matrix_1);
    //printMatrix(symmetric_matrix_2);
    printMatrix(result);

    return 0;
}
