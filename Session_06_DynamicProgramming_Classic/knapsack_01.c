#include <stdio.h>
#include <stdlib.h>

/*
 * Session 06: 0/1 Knapsack Problem in C
 * Uses bottom-up tabulation to find the optimal item combination for a given capacity
 * and backtracks to determine exactly which items were selected.
 * Time Complexity: O(n * W)
 * Space Complexity: O(n * W)
 */

int max(int a, int b) {
    return (a > b) ? a : b;
}

void solveKnapsack(int weights[], int values[], int n, int W) {
    // Allocate 2D DP table
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    // Fill DP Table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print DP table
    printf("DP Table (Rows: Items 0..%d, Columns: Capacity 0..%d):\n", n, W);
    for (int i = 0; i <= n; i++) {
        printf("Item %d: ", i);
        for (int w = 0; w <= W; w++) {
            printf("%3d ", dp[i][w]);
        }
        printf("\n");
    }
    printf("\nMaximum value possible in Knapsack: %d\n", dp[n][W]);

    // Backtrack to find selected items
    printf("Selected Items:\n");
    int w = W;
    for (int i = n; i > 0; i--) {
        // If the value changed from the row above, the item was selected
        if (dp[i][w] != dp[i - 1][w]) {
            printf("  Item ID %d: Value = %d, Weight = %d\n", i, values[i - 1], weights[i - 1]);
            w -= weights[i - 1]; // Reduce remaining capacity
        }
    }

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);
    int W = 50;

    printf("=== Dynamic Programming: 0/1 Knapsack ===\n");
    printf("Knapsack capacity: %d\n\n", W);
    
    solveKnapsack(weights, values, n, W);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
