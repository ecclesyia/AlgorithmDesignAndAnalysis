import sys

def fib_naive(n):
    if n <= 1:
        return n
    return fib_naive(n - 1) + fib_naive(n - 2)

def fib_memoize_helper(n, memo):
    if memo[n] != -1:
        return memo[n]
    if n <= 1:
        memo[n] = n
        return n
    memo[n] = fib_memoize_helper(n - 1, memo) + fib_memoize_helper(n - 2, memo)
    return memo[n]

def fib_memoization(n):
    memo = [-1] * (n + 1)
    return fib_memoize_helper(n, memo)

def fib_tabulation(n):
    if n <= 1:
        return n
    table = [0] * (n + 1)
    table[0] = 0
    table[1] = 1
    for i in range(2, n + 1):
        table[i] = table[i - 1] + table[i - 2]
    return table[n]

def main():
    n = 35
    print(f"Fib({n}) Naive: {fib_naive(n)}")
    print(f"Fib({n}) Memo: {fib_memoization(n)}")
    print(f"Fib({n}) Tab: {fib_tabulation(n)}")
    print()
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
