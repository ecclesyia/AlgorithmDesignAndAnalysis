#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Session 11: N-Queens Problem in C
 * Solves the N-Queens puzzle using a recursive backtracking algorithm.
 * Time Complexity: O(N!)
 * Space Complexity: O(N^2) for the board
 */

#define N 4 // Size of the board (NxN)

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf(" Q ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Recursive helper to solve N-Queens
bool solveNQueensHelper(int board[N][N], int col) {
    // Base Case: If all queens are placed, return true
    if (col >= N) {
        return true;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place this queen on board[i][col]
            board[i][col] = 1;
            
            printf("Trying placement at Row %d, Col %d:\n", i, col);
            printBoard(board);

            // Recur to place rest of the queens
            if (solveNQueensHelper(board, col + 1)) {
                return true;
            }

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then backtrack (remove queen)
            board[i][col] = 0;
            printf("Backtracking: Removed Queen from Row %d, Col %d\n\n", i, col);
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

void solveNQueens() {
    int board[N][N] = {0};

    if (solveNQueensHelper(board, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    printf("=== Final Solution Found ===\n");
    printBoard(board);
}

int main() {
    printf("=== Backtracking: N-Queens Solver (N = %d) ===\n\n", N);
    solveNQueens();

    printf("Press Enter to exit...");
    getchar();
    return 0;
}
