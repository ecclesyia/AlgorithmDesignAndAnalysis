#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Session 01: Time Complexity Examples in C
 * This file illustrates different time complexities using counting variables
 * to track the exact number of operations performed for a given input size n.
 */

// Constant Time: O(1)
// The number of operations is fixed and does not change with n.
void demonstrateConstantTime(int n) {
    int operations = 0;
    
    // Independent statements
    int a = 10;
    operations++;
    
    int b = 20;
    operations++;
    
    int sum = a + b;
    operations++;
    
    printf("O(1) Constant Time:\n");
    printf("  Input size (n): %d\n", n);
    printf("  Actual operations counted: %d\n\n", operations);
}

// Logarithmic Time: O(log n)
// The input size is divided by a constant factor in each iteration (base 2).
void demonstrateLogarithmicTime(int n) {
    int operations = 0;
    int temp = n;
    
    printf("O(log n) Logarithmic Time:\n");
    printf("  Dividing input size %d by 2 repeatedly:\n", n);
    
    while (temp > 1) {
        printf("    Current value: %d\n", temp);
        temp /= 2;
        operations++;
    }
    
    printf("  Input size (n): %d\n", n);
    printf("  Actual operations counted: %d\n\n", operations);
}

// Linear Time: O(n)
// The number of operations grows in direct proportion to the input size n.
void demonstrateLinearTime(int n) {
    int operations = 0;
    
    for (int i = 0; i < n; i++) {
        operations++;
    }
    
    printf("O(n) Linear Time:\n");
    printf("  Input size (n): %d\n", n);
    printf("  Actual operations counted: %d\n\n", operations);
}

// Linearithmic Time: O(n log n)
// A combination of outer linear iteration and inner logarithmic division.
// This is typical of divide-and-conquer algorithms like Merge Sort.
void demonstrateLinearithmicTime(int n) {
    int operations = 0;
    
    for (int i = 0; i < n; i++) {
        int temp = n;
        while (temp > 1) {
            temp /= 2;
            operations++;
        }
    }
    
    printf("O(n log n) Linearithmic Time:\n");
    printf("  Input size (n): %d\n", n);
    printf("  Actual operations counted: %d\n\n", operations);
}

// Quadratic Time: O(n^2)
// Nested loops where both run n times. Common in simple sorting like Bubble Sort.
void demonstrateQuadraticTime(int n) {
    int operations = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            operations++;
        }
    }
    
    printf("O(n^2) Quadratic Time:\n");
    printf("  Input size (n): %d\n", n);
    printf("  Actual operations counted: %d (n * n)\n\n", operations, n);
}

int main() {
    int n = 16; // Using 16 as it is a power of 2, making logarithmic division neat.
    
    printf("=== Time Complexity Visualizer ===\n");
    printf("This program counts operations to demonstrate theoretical time complexities.\n\n");
    
    demonstrateConstantTime(n);
    demonstrateLogarithmicTime(n);
    demonstrateLinearTime(n);
    demonstrateLinearithmicTime(n);
    demonstrateQuadraticTime(n);
    
    printf("Press Enter to exit...");
    getchar();
    return 0;
}
