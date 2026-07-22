import sys

INF = int(1e9)

def get_min_coins(coins, amount):
    dp = [0] + [INF] * amount
    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i:
                sub_res = dp[i - coin]
                if sub_res != INF and sub_res + 1 < dp[i]:
                    dp[i] = sub_res + 1
    result = dp[amount]
    return -1 if result == INF else result

def main():
    coins = [1, 3, 4]
    amount = 6
    print(f"Min coins required: {get_min_coins(coins, amount)}")
    print()
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
