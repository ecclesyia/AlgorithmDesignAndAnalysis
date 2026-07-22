import java.util.Scanner

fun fibNaive(n: Int): Long {
    if (n <= 1) return n.toLong()
    return fibNaive(n - 1) + fibNaive(n - 2)
}

fun fibMemoizeHelper(n: Int, memo: LongArray): Long {
    if (memo[n] != -1L) return memo[n]
    if (n <= 1) {
        memo[n] = n.toLong()
        return memo[n]
    }
    memo[n] = fibMemoizeHelper(n - 1, memo) + fibMemoizeHelper(n - 2, memo)
    return memo[n]
}

fun fibMemoization(n: Int): Long {
    val memo = LongArray(n + 1) { -1L }
    return fibMemoizeHelper(n, memo)
}

fun fibTabulation(n: Int): Long {
    if (n <= 1) return n.toLong()
    val table = LongArray(n + 1)
    table[0] = 0L
    table[1] = 1L
    for (i in 2..n) {
        table[i] = table[i - 1] + table[i - 2]
    }
    return table[n]
}

fun main() {
    val n = 35
    println("Fib($n) Naive: ${fibNaive(n)}")
    println("Fib($n) Memo: ${fibMemoization(n)}")
    println("Fib($n) Tab: ${fibTabulation(n)}")
    println()
    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
