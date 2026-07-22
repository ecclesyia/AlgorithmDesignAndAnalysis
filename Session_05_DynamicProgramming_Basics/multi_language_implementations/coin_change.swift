import Foundation

let INF = 1000000000

func getMinCoins(_ coins: [Int], _ amount: Int) -> Int {
    var dp = [Int](repeating: INF, count: amount + 1)
    dp[0] = 0
    for i in 1...amount {
        for j in 0..<coins.count {
            if coins[j] <= i {
                let subRes = dp[i - coins[j]]
                if subRes != INF && subRes + 1 < dp[i] {
                    dp[i] = subRes + 1
                }
            }
        }
    }
    let result = dp[amount]
    return result == INF ? -1 : result
}

func main() {
    let coins = [1, 3, 4]
    let amount = 6
    print("Min coins required: \(getMinCoins(coins, amount))")
    print("\nPress Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
