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

func solveLCS(s1 string, s2 string) {
	m := len(s1)
	n := len(s2)
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for i := 0; i <= m; i++ {
		for j := 0; j <= n; j++ {
			if i == 0 || j == 0 {
				dp[i][j] = 0
			} else if s1[i-1] == s2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}

	fmt.Printf("LCS Length: %d\n", dp[m][n])

	index := dp[m][n]
	lcsStr := make([]byte, index)
	i, j := m, n
	for i > 0 && j > 0 {
		if s1[i-1] == s2[j-1] {
			lcsStr[index-1] = s1[i-1]
			i--
			j--
			index--
		} else if dp[i-1][j] > dp[i][j-1] {
			i--
		} else {
			j--
		}
	}
	fmt.Printf("LCS String: %s\n", string(lcsStr))
}

func main() {
	s1 := "STONE"
	s2 := "LONEST"
	solveLCS(s1, s2)
	fmt.Printf("\nPress Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
