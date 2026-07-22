#include <iostream>
#include <vector>

const int INF = 1e9;

int getMinCoins(const std::vector<int> &coins, int amount) {
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (size_t j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                int subRes = dp[i - coins[j]];
                if (subRes != INF && subRes + 1 < dp[i]) {
                    dp[i] = subRes + 1;
                }
            }
        }
    }
    int result = dp[amount];
    return (result == INF) ? -1 : result;
}

int main() {
    std::vector<int> coins = {1, 3, 4};
    int amount = 6;
    std::cout << "Min coins required: " << getMinCoins(coins, amount) << "\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}
