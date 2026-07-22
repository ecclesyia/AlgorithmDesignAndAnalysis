import Foundation

func solveLCS(_ s1: String, _ s2: String) {
    let m = s1.count
    let n = s2.count
    let chars1 = Array(s1)
    let chars2 = Array(s2)
    var dp = [[Int]](repeating: [Int](repeating: 0, count: n + 1), count: m + 1)

    for i in 0...m {
        for j in 0...n {
            if i == 0 || j == 0 {
                dp[i][j] = 0
            } else if chars1[i - 1] == chars2[j - 1] {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            }
        }
    }
    print("LCS Length: \(dp[m][n])")

    var index = dp[m][n]
    var lcsStr = [Character](repeating: " ", count: index)
    var i = m
    var j = n
    while i > 0 && j > 0 {
        if chars1[i - 1] == chars2[j - 1] {
            lcsStr[index - 1] = chars1[i - 1]
            i -= 1
            j -= 1
            index -= 1
        } else if dp[i - 1][j] > dp[i][j - 1] {
            i -= 1
        } else {
            j -= 1
        }
    }
    print("LCS String: \(String(lcsStr))")
}

func main() {
    let s1 = "STONE"
    let s2 = "LONEST"
    solveLCS(s1, s2)
    print("\nPress Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
