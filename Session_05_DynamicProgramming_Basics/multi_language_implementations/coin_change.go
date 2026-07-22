package main

import (
	"bufio"
	"fmt"
	"os"
)

const INF = 1e9

func getMinCoins(coins []int, amount int) int {
	dp := make([]int, amount+1)
	dp[0] = 0
	for i := 1; i <= amount; i++ {
		dp[i] = INF
	}
	for i := 1; i <= amount; i++ {
		for j := 0; j < len(coins); j++ {
			if coins[j] <= i {
				subRes := dp[i-coins[j]]
				if subRes != INF && subRes+1 < dp[i] {
					dp[i] = subRes + 1
				}
			}
		}
	}
	result := dp[amount]
	if result == INF {
		return -1
	}
	return result
}

func main() {
	coins := []int{1, 3, 4}
	amount := 6
	fmt.Printf("Min coins required: %d\n", getMinCoins(coins, amount))
	fmt.Printf("\nPress Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
