import java.util.Scanner
import kotlin.math.max

fun solveLCS(s1: String, s2: String) {
    val m = s1.length
    val n = s2.length
    val dp = Array(m + 1) { IntArray(n + 1) }

    for (i in 0..m) {
        for (j in 0..n) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            }
        }
    }
    println("LCS Length: ${dp[m][n]}")

    var index = dp[m][n]
    val lcsStr = CharArray(index)
    var i = m
    var j = n
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcsStr[index - 1] = s1[i - 1]
            i--
            j--
            index--
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--
        } else {
            j--
        }
    }
    println("LCS String: ${String(lcsStr)}")
}

fun main() {
    val s1 = "STONE"
    val s2 = "LONEST"
    solveLCS(s1, s2)
    println()
    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
