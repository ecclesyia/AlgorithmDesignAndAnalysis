#include <stdio.h>
#include <stdlib.h>

/*
 * Session 05: Coin Change Problem in C
 * Solves the minimum coins change problem using Bottom-Up Tabulation.
 * Time Complexity: O(amount * numCoins)
 * Space Complexity: O(amount) for DP table
 */

#define INF 1e9 // Represent infinity

int getMinCoins(int coins[], int numCoins, int amount) {
    // dp[i] will store the minimum coins needed for amount i
    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    
    // Base Case: 0 coins needed for amount 0
    dp[0] = 0;
    
    // Initialize all other values as infinity
    for (int i = 1; i <= amount; i++) {
        dp[i] = INF;
    }
    
    // Build the table bottom-up
    for (int i = 1; i <= amount; i++) {
        // Check every coin denomination
        for (int j = 0; j < numCoins; j++) {
            if (coins[j] <= i) {
                int subRes = dp[i - coins[j]];
                // If the subproblem is solvable, check if using this coin minimizes count
                if (subRes != INF && subRes + 1 < dp[i]) {
                    dp[i] = subRes + 1;
                }
            }
        }
    }
    
    int result = dp[amount];
    free(dp);
    
    // If dp[amount] remains INF, it means the amount cannot be formed
    return (result == INF) ? -1 : result;
}

int main() {
    int coins[] = {1, 3, 4};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int amount = 6;
    
    printf("=== Dynamic Programming: Coin Change ===\n");
    printf("Available Coin Denominations: ");
    for (int i = 0; i < numCoins; i++) {
        printf("%d ", coins[i]);
    }
    printf("\nTarget Amount: %d\n\n", amount);
    
    int minCoins = getMinCoins(coins, numCoins, amount);
    
    if (minCoins != -1) {
        printf("Minimum coins required to make change for %d is: %d\n", amount, minCoins);
    } else {
        printf("It is impossible to make change for %d using the given coins.\n", amount);
    }
    
    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
