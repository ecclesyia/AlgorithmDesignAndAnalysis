import Foundation

func solveKnapsack(_ weights: [Int], _ values: [Int], _ n: Int, _ W: Int) {
    var dp = [[Int]](repeating: [Int](repeating: 0, count: W + 1), count: n + 1)
    for i in 0...n {
        for w in 0...W {
            if i == 0 || w == 0 {
                dp[i][w] = 0
            } else if weights[i - 1] <= w {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            } else {
                dp[i][w] = dp[i - 1][w]
            }
        }
    }
    print("Max Knapsack value: \(dp[n][W])")
    var w = W
    for i in stride(from: n, through: 1, by: -1) {
        if dp[i][w] != dp[i - 1][w] {
            print("  Selected: Item ID \(i) (Val: \(values[i - 1]), Wt: \(weights[i - 1]))")
            w -= weights[i - 1]
        }
    }
}

func main() {
    let values = [60, 100, 120]
    let weights = [10, 20, 30]
    solveKnapsack(weights, values, 3, 50)
    print("\nPress Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
