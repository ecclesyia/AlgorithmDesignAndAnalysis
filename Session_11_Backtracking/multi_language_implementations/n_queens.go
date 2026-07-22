package main

import (
	"bufio"
	"fmt"
	"os"
)

const N = 4

func printBoard(board [N][N]int) {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if board[i][j] == 1 {
				fmt.Print(" Q ")
			} else {
				fmt.Print(" . ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func isSafe(board [N][N]int, row, col int) bool {
	// Check this row on left side
	for i := 0; i < col; i++ {
		if board[row][i] == 1 {
			return false
		}
	}

	// Check upper diagonal on left side
	for i, j := row, col; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if board[i][j] == 1 {
			return false
		}
	}

	// Check lower diagonal on left side
	for i, j := row, col; j >= 0 && i < N; i, j = i+1, j-1 {
		if board[i][j] == 1 {
			return false
		}
	}

	return true
}

func solveNQueensHelper(board *[N][N]int, col int) bool {
	if col >= N {
		return true
	}

	for i := 0; i < N; i++ {
		if isSafe(*board, i, col) {
			board[i][col] = 1

			fmt.Printf("Trying placement at Row %d, Col %d:\n", i, col)
			printBoard(*board)

			if solveNQueensHelper(board, col+1) {
				return true
			}

			board[i][col] = 0
			fmt.Printf("Backtracking: Removed Queen from Row %d, Col %d\n\n", i, col)
		}
	}

	return false
}

func solveNQueens() {
	var board [N][N]int

	if !solveNQueensHelper(&board, 0) {
		fmt.Println("Solution does not exist")
		return
	}

	fmt.Println("=== Final Solution Found ===")
	printBoard(board)
}

func main() {
	fmt.Printf("=== Backtracking: N-Queens Solver (N = %d) ===\n\n", N)
	solveNQueens()

	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
