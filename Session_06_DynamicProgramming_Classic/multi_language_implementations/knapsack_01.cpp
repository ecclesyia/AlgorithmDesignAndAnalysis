#include <iostream>
#include <vector>
#include <algorithm>

void solveKnapsack(const std::vector<int> &weights, const std::vector<int> &values, int n, int W) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else dp[i][w] = dp[i - 1][w];
        }
    }
    std::cout << "Max Knapsack value: " << dp[n][W] << "\n";
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            std::cout << "  Selected: Item ID " << i << " (Val: " << values[i - 1] << ", Wt: " << weights[i - 1] << ")\n";
            w -= weights[i - 1];
        }
    }
}

int main() {
    std::vector<int> values = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    solveKnapsack(weights, values, 3, 50);
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}
