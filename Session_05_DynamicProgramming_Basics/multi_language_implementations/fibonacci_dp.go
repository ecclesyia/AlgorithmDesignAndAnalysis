package main

import (
	"bufio"
	"fmt"
	"os"
)

func fibNaive(n int) int64 {
	if n <= 1 {
		return int64(n)
	}
	return fibNaive(n-1) + fibNaive(n-2)
}

func fibMemoizeHelper(n int, memo []int64) int64 {
	if memo[n] != -1 {
		return memo[n]
	}
	if n <= 1 {
		memo[n] = int64(n)
		return memo[n]
	}
	memo[n] = fibMemoizeHelper(n-1, memo) + fibMemoizeHelper(n-2, memo)
	return memo[n]
}

func fibMemoization(n int) int64 {
	memo := make([]int64, n+1)
	for i := 0; i <= n; i++ {
		memo[i] = -1
	}
	return fibMemoizeHelper(n, memo)
}

func fibTabulation(n int) int64 {
	if n <= 1 {
		return int64(n)
	}
	table := make([]int64, n+1)
	table[0] = 0
	table[1] = 1
	for i := 2; i <= n; i++ {
		table[i] = table[i-1] + table[i-2]
	}
	return table[n]
}

func main() {
	n := 35
	fmt.Printf("Fib(%d) Naive: %d\n", n, fibNaive(n))
	fmt.Printf("Fib(%d) Memo: %d\n", n, fibMemoization(n))
	fmt.Printf("Fib(%d) Tab: %d\n", n, fibTabulation(n))
	fmt.Printf("\nPress Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
