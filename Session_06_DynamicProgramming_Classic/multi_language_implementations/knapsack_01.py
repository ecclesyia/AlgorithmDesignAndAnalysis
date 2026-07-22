import sys

def solve_knapsack(weights, values, n, W):
    dp = [[0] * (W + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]
                
    print(f"Max Knapsack value: {dp[n][W]}")
    w = W
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:
            print(f"  Selected: Item ID {i} (Val: {values[i - 1]}, Wt: {weights[i - 1]})")
            w -= weights[i - 1]

def main():
    values = [60, 100, 120]
    weights = [10, 20, 30]
    solve_knapsack(weights, values, 3, 50)
    print()
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
