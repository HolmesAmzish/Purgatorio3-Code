#include <stdio.h>

void snakePattern(int A[][100], int n, int B[], int *index) {
    int i, j, k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            B[*index] = A[i][j];
            (*index)++;
        }
        if (i % 2 == 0) {
            for (j = n - 2; j >= 1; j--) {
                B[*index] = A[i][j];
                (*index)++;
            }
        } else {
            for (j = 1; j < n; j++) {
                B[*index] = A[i][j];
                (*index)++;
            }
        }
    }
}

void printMatrix(int A[][100], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    scanf("%d", &n);

    int A[100][100]; // 假设矩阵最大为100x100
    int B[10000]; // 假设一维数组最大为10000个元素
    int index = 0; // 用于记录一维数组的当前位置

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    snakePattern(A, n, B, &index);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", B[i * n + j]);
        }
        printf("\n");
    }

    printMatrix(A, n);

    for (i = 0; i < index; i++) {
        printf("%d ", B[i]);
        if (i % n == n - 1) {
            printf("\n");
        }
    }

    return 0;
}