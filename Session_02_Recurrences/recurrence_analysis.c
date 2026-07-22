#include <stdio.h>
#include <stdlib.h>

/*
 * Session 02: Recursion and Stack Depth Visualizer in C
 * This file demonstrates how recursive functions create stack frames,
 * how to visualize the execution tree, and how to track recursion depth.
 */

// Helper to print indentation reflecting stack depth
void printIndent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  |  ");
    }
}

// Factorial recursive function with call stack visualization.
// Time complexity: O(n)
// Space complexity: O(n) due to stack frames.
long long calculateFactorial(int n, int depth) {
    printIndent(depth);
    printf("Entering factorial(%d). Address of n: %p\n", n, (void*)&n);

    // Base Case
    if (n <= 1) {
        printIndent(depth);
        printf("Base Case reached for factorial(%d). Returning 1.\n", n);
        return 1;
    }

    // Recursive Case
    long long subResult = calculateFactorial(n - 1, depth + 1);
    long long result = n * subResult;

    printIndent(depth);
    printf("Exiting factorial(%d) -> returning %lld * %lld = %lld\n", n, (long long)n, subResult, result);
    return result;
}

// Fibonacci recursive function with call tree visualization.
// Time complexity: O(2^n) - exponential growth of stack frames!
// Space complexity: O(n) - maximum depth of recursion stack.
int calculateFibonacci(int n, int depth, const char *branch) {
    printIndent(depth);
    printf("Entering fibonacci(%d) [%s branch]. Address of n: %p\n", n, branch, (void*)&n);

    // Base Cases
    if (n == 0) {
        printIndent(depth);
        printf("Base Case: fibonacci(0) = 0. Returning.\n");
        return 0;
    }
    if (n == 1) {
        printIndent(depth);
        printf("Base Case: fibonacci(1) = 1. Returning.\n");
        return 1;
    }

    // Recursive Calls
    int left = calculateFibonacci(n - 1, depth + 1, "Left");
    int right = calculateFibonacci(n - 2, depth + 1, "Right");
    int result = left + right;

    printIndent(depth);
    printf("Exiting fibonacci(%d) -> returning %d + %d = %d\n", n, left, right, result);
    return result;
}

int main() {
    int val = 5;
    
    printf("=== Recursion & Stack Frame Visualizer ===\n\n");
    
    printf("--- PART 1: Linear Recursion - Factorial(%d) ---\n", val);
    printf("Notice how the call stack depth grows linearly and variables have distinct memory addresses.\n\n");
    long long fact = calculateFactorial(val, 0);
    printf("\nFactorial of %d is: %lld\n\n", val, fact);
    
    printf("--------------------------------------------------\n\n");
    
    printf("--- PART 2: Tree Recursion - Fibonacci(4) ---\n");
    printf("Notice how the tree structure branches out, leading to redundant calculations.\n\n");
    int fib = calculateFibonacci(4, 0, "Root");
    printf("\nFibonacci of 4 is: %d\n\n", fib);
    
    printf("Press Enter to exit...");
    getchar();
    return 0;
}
