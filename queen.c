#include <stdio.h>

#define N 8

int board[N][N];

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

int solveNQ(int row) {
    if (row == N) {
        printSolution();
        return 1;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solveNQ(row + 1)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQ(0)) {
        printf("Solution does not exist\n");
    }

    return 0;
}
