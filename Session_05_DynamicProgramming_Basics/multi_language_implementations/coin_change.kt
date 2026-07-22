import java.util.Scanner

const val INF = 1e9.toInt()

fun getMinCoins(coins: IntArray, amount: Int): Int {
    val dp = IntArray(amount + 1)
    dp[0] = 0
    for (i in 1..amount) {
        dp[i] = INF
    }
    for (i in 1..amount) {
        for (j in coins.indices) {
            if (coins[j] <= i) {
                val subRes = dp[i - coins[j]]
                if (subRes != INF && subRes + 1 < dp[i]) {
                    dp[i] = subRes + 1
                }
            }
        }
    }
    val result = dp[amount]
    return if (result == INF) -1 else result
}

fun main() {
    val coins = intArrayOf(1, 3, 4)
    val amount = 6
    println("Min coins required: ${getMinCoins(coins, amount)}")
    println()
    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
