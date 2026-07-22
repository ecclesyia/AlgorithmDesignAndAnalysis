#include <iostream>
#include <vector>

long long fibNaive(int n) {
    if (n <= 1) return n;
    return fibNaive(n - 1) + fibNaive(n - 2);
}

long long fibMemoizeHelper(int n, std::vector<long long> &memo) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) {
        memo[n] = n;
        return n;
    }
    memo[n] = fibMemoizeHelper(n - 1, memo) + fibMemoizeHelper(n - 2, memo);
    return memo[n];
}

long long fibMemoization(int n) {
    std::vector<long long> memo(n + 1, -1);
    return fibMemoizeHelper(n, memo);
}

long long fibTabulation(int n) {
    if (n <= 1) return n;
    std::vector<long long> table(n + 1);
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}

int main() {
    int n = 35;
    std::cout << "Fib(" << n << ") Naive: " << fibNaive(n) << "\n";
    std::cout << "Fib(" << n << ") Memo: " << fibMemoization(n) << "\n";
    std::cout << "Fib(" << n << ") Tab: " << fibTabulation(n) << "\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}
