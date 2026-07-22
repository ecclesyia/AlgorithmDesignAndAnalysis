package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solveKnapsack(weights []int, values []int, n int, W int) {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, W+1)
	}

	for i := 0; i <= n; i++ {
		for w := 0; w <= W; w++ {
			if i == 0 || w == 0 {
				dp[i][w] = 0
			} else if weights[i-1] <= w {
				dp[i][w] = max(dp[i-1][w], values[i-1]+dp[i-1][w-weights[i-1]])
			} else {
				dp[i][w] = dp[i-1][w]
			}
		}
	}

	fmt.Printf("Max Knapsack value: %d\n", dp[n][W])
	w := W
	for i := n; i > 0; i-- {
		if dp[i][w] != dp[i-1][w] {
			fmt.Printf("  Selected: Item ID %d (Val: %d, Wt: %d)\n", i, values[i-1], weights[i-1])
			w -= weights[i-1]
		}
	}
}

func main() {
	values := []int{60, 100, 120}
	weights := []int{10, 20, 30}
	solveKnapsack(weights, values, 3, 50)
	fmt.Printf("\nPress Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
