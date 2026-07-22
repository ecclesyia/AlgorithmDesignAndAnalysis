import Foundation

func fibNaive(_ n: Int) -> Int64 {
    if n <= 1 {
        return Int64(n)
    }
    return fibNaive(n - 1) + fibNaive(n - 2)
}

func fibMemoizeHelper(_ n: Int, _ memo: inout [Int64]) -> Int64 {
    if memo[n] != -1 {
        return memo[n]
    }
    if n <= 1 {
        memo[n] = Int64(n)
        return memo[n]
    }
    memo[n] = fibMemoizeHelper(n - 1, &memo) + fibMemoizeHelper(n - 2, &memo)
    return memo[n]
}

func fibMemoization(_ n: Int) -> Int64 {
    var memo = [Int64](repeating: -1, count: n + 1)
    return fibMemoizeHelper(n, &memo)
}

func fibTabulation(_ n: Int) -> Int64 {
    if n <= 1 {
        return Int64(n)
    }
    var table = [Int64](repeating: 0, count: n + 1)
    table[0] = 0
    table[1] = 1
    for i in 2...n {
        table[i] = table[i - 1] + table[i - 2]
    }
    return table[n]
}

func main() {
    let n = 35
    print("Fib(\(n)) Naive: \(fibNaive(n))")
    print("Fib(\(n)) Memo: \(fibMemoization(n))")
    print("Fib(\(n)) Tab: \(fibTabulation(n))")
    print("\nPress Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
