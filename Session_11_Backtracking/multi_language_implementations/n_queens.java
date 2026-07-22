// Session 11: N-Queens Backtracking in Java

public class n_queens {
    private static final int N = 4;

    public static void printBoard(int[][] board) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(board[i][j] != 0 ? " Q " : " . ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static boolean isSafe(int[][] board, int row, int col) {
        int i, j;
        for (i = 0; i < col; i++) {
            if (board[row][i] != 0) {
                return false;
            }
        }
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] != 0) {
                return false;
            }
        }
        for (i = row, j = col; j >= 0 && i < N; i++, j--) {
            if (board[i][j] != 0) {
                return false;
            }
        }
        return true;
    }

    public static boolean solveNQueensHelper(int[][] board, int col) {
        if (col >= N) {
            return true;
        }
        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;
                if (solveNQueensHelper(board, col + 1)) {
                    return true;
                }
                board[i][col] = 0; // backtrack
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] board = new int[N][N];
        if (solveNQueensHelper(board, 0)) {
            printBoard(board);
        } else {
            System.out.println("No solution");
        }
    }
}
