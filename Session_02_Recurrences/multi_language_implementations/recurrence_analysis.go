package main

import (
	"bufio"
	"fmt"
	"os"
)

func printIndent(depth int) {
	for i := 0; i < depth; i++ {
		fmt.Printf("  |  ")
	}
}

func calculateFactorial(n int, depth int) int64 {
	printIndent(depth)
	fmt.Printf("Entering factorial(%d). Address of n: %p\n", n, &n)
	if n <= 1 {
		printIndent(depth)
		fmt.Printf("Base Case reached for factorial(%d). Returning 1.\n", n)
		return 1
	}
	subResult := calculateFactorial(n-1, depth+1)
	result := int64(n) * subResult
	printIndent(depth)
	fmt.Printf("Exiting factorial(%d) -> returning %d * %d = %d\n", n, n, subResult, result)
	return result
}

func calculateFibonacci(n int, depth int, branch string) int {
	printIndent(depth)
	fmt.Printf("Entering fibonacci(%d) [%s branch]. Address of n: %p\n", n, branch, &n)
	if n == 0 {
		printIndent(depth)
		fmt.Printf("Base Case: fibonacci(0) = 0. Returning.\n")
		return 0
	}
	if n == 1 {
		printIndent(depth)
		fmt.Printf("Base Case: fibonacci(1) = 1. Returning.\n")
		return 1
	}
	left := calculateFibonacci(n-1, depth+1, "Left")
	right := calculateFibonacci(n-2, depth+1, "Right")
	result := left + right
	printIndent(depth)
	fmt.Printf("Exiting fibonacci(%d) -> returning %d + %d = %d\n", n, left, right, result)
	return result
}

func main() {
	val := 5
	fmt.Printf("=== Recursion & Stack Frame Visualizer ===\n\n")
	fmt.Printf("--- PART 1: Linear Recursion - Factorial(%d) ---\n", val)
	fact := calculateFactorial(val, 0)
	fmt.Printf("\nFactorial of %d is: %d\n\n", val, fact)
	fmt.Printf("--------------------------------------------------\n\n")
	fmt.Printf("--- PART 2: Tree Recursion - Fibonacci(4) ---\n")
	fib := calculateFibonacci(4, 0, "Root")
	fmt.Printf("\nFibonacci of 4 is: %d\n\n", fib)
	fmt.Printf("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
