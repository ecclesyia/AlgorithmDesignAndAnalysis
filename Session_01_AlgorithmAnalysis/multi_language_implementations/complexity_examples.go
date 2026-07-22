package main

import (
	"bufio"
	"fmt"
	"os"
)

func demonstrateConstantTime(n int) {
	operations := 0
	a := 10
	operations++
	b := 20
	operations++
	_ = a + b
	operations++
	fmt.Printf("O(1) Constant Time:\n")
	fmt.Printf("  Input size (n): %d\n", n)
	fmt.Printf("  Actual operations counted: %d\n\n", operations)
}

func demonstrateLogarithmicTime(n int) {
	operations := 0
	temp := n
	fmt.Printf("O(log n) Logarithmic Time:\n")
	fmt.Printf("  Dividing input size %d by 2 repeatedly:\n", n)
	for temp > 1 {
		fmt.Printf("    Current value: %d\n", temp)
		temp /= 2
		operations++
	}
	fmt.Printf("  Input size (n): %d\n", n)
	fmt.Printf("  Actual operations counted: %d\n\n", operations)
}

func demonstrateLinearTime(n int) {
	operations := 0
	for i := 0; i < n; i++ {
		operations++
	}
	fmt.Printf("O(n) Linear Time:\n")
	fmt.Printf("  Input size (n): %d\n", n)
	fmt.Printf("  Actual operations counted: %d\n\n", operations)
}

func demonstrateLinearithmicTime(n int) {
	operations := 0
	for i := 0; i < n; i++ {
		temp := n
		for temp > 1 {
			temp /= 2
			operations++
		}
	}
	fmt.Printf("O(n log n) Linearithmic Time:\n")
	fmt.Printf("  Input size (n): %d\n", n)
	fmt.Printf("  Actual operations counted: %d\n\n", operations)
}

func demonstrateQuadraticTime(n int) {
	operations := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			operations++
		}
	}
	fmt.Printf("O(n^2) Quadratic Time:\n")
	fmt.Printf("  Input size (n): %d\n", n)
	fmt.Printf("  Actual operations counted: %d (n * n)\n\n", operations, n)
}

func main() {
	n := 16
	fmt.Printf("=== Time Complexity Visualizer ===\n")
	fmt.Printf("This program counts operations to demonstrate theoretical time complexities.\n\n")
	demonstrateConstantTime(n)
	demonstrateLogarithmicTime(n)
	demonstrateLinearTime(n)
	demonstrateLinearithmicTime(n)
	demonstrateQuadraticTime(n)
	fmt.Printf("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
