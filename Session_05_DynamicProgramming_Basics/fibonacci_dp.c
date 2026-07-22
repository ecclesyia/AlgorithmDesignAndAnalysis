#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Session 05: Fibonacci Comparison in C
 * Compares standard recursion (exponential) with Dynamic Programming:
 * 1. Memoization (Top-Down recursion + cache)
 * 2. Tabulation (Bottom-Up iteration + table)
 * 3. Space-Optimized Tabulation (O(1) auxiliary space)
 */

long long recursionCount = 0;
long long memoizationCount = 0;

// 1. Standard Recursion: O(2^n) time, O(n) stack space
long long fibNaive(int n) {
    recursionCount++;
    if (n <= 1) return n;
    return fibNaive(n - 1) + fibNaive(n - 2);
}

// Helper for Memoization
long long fibMemoizeHelper(int n, long long memo[]) {
    memoizationCount++;
    if (memo[n] != -1) return memo[n]; // Return cached value
    
    if (n <= 1) {
        memo[n] = n;
        return n;
    }

    memo[n] = fibMemoizeHelper(n - 1, memo) + fibMemoizeHelper(n - 2, memo);
    return memo[n];
}

// 2. Memoization (Top-Down DP): O(n) time, O(n) auxiliary space
long long fibMemoization(int n) {
    long long *memo = (long long *)malloc((n + 1) * sizeof(long long));
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    long long result = fibMemoizeHelper(n, memo);
    free(memo);
    return result;
}

// 3. Tabulation (Bottom-Up DP): O(n) time, O(n) auxiliary space
long long fibTabulation(int n) {
    if (n <= 1) return n;
    
    long long *table = (long long *)malloc((n + 1) * sizeof(long long));
    table[0] = 0;
    table[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    
    long long result = table[n];
    free(table);
    return result;
}

// 4. Space-Optimized Tabulation: O(n) time, O(1) space
long long fibSpaceOptimized(int n) {
    if (n <= 1) return n;
    
    long long prev2 = 0;
    long long prev1 = 1;
    long long current = 0;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

int main() {
    int n = 35; // Size chosen to show the dramatic slowdown of naive recursion
    
    printf("=== Dynamic Programming: Fibonacci Comparison ===\n");
    printf("Calculating fib(%d):\n\n", n);
    
    // Naive Recursion
    clock_t start = clock();
    long long resNaive = fibNaive(n);
    clock_t end = clock();
    double timeNaive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("1. Naive Recursion:\n");
    printf("  Result: %lld\n", resNaive);
    printf("  Function calls: %lld\n", recursionCount);
    printf("  Execution time: %.6f seconds\n\n", timeNaive);
    
    // Memoization (Top-Down)
    start = clock();
    long long resMemo = fibMemoization(n);
    end = clock();
    double timeMemo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("2. Memoization (Top-Down DP):\n");
    printf("  Result: %lld\n", resMemo);
    printf("  Function calls: %lld (Huge reduction!)\n", memoizationCount);
    printf("  Execution time: %.6f seconds\n\n", timeMemo);
    
    // Tabulation (Bottom-Up)
    start = clock();
    long long resTab = fibTabulation(n);
    end = clock();
    double timeTab = (double)(end - start) / CLOCKS_PER_SEC;
    printf("3. Tabulation (Bottom-Up DP):\n");
    printf("  Result: %lld\n", resTab);
    printf("  Execution time: %.6f seconds\n\n", timeTab);
    
    // Space-Optimized Tabulation
    start = clock();
    long long resOpt = fibSpaceOptimized(n);
    end = clock();
    double timeOpt = (double)(end - start) / CLOCKS_PER_SEC;
    printf("4. Space-Optimized Tabulation:\n");
    printf("  Result: %lld\n", resOpt);
    printf("  Execution time: %.6f seconds\n\n", timeOpt);
    
    printf("Press Enter to exit...");
    getchar();
    return 0;
}
