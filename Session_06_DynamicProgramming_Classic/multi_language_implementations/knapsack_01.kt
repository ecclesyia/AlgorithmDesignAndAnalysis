import java.util.Scanner
import kotlin.math.max

fun solveKnapsack(weights: IntArray, values: IntArray, n: Int, W: Int) {
    val dp = Array(n + 1) { IntArray(W + 1) }
    for (i in 0..n) {
        for (w in 0..W) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            } else {
                dp[i][w] = dp[i - 1][w]
            }
        }
    }
    println("Max Knapsack value: ${dp[n][W]}")
    var w = W
    for (i in n downTo 1) {
        if (dp[i][w] != dp[i - 1][w]) {
            println("  Selected: Item ID $i (Val: ${values[i - 1]}, Wt: ${weights[i - 1]})")
            w -= weights[i - 1]
        }
    }
}

fun main() {
    val values = intArrayOf(60, 100, 120)
    val weights = intArrayOf(10, 20, 30)
    solveKnapsack(weights, values, 3, 50)
    println()
    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
