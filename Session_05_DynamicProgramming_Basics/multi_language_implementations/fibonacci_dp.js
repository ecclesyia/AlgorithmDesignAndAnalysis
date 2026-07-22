const readline = require('readline');

function fibNaive(n) {
    if (n <= 1) return BigInt(n);
    return fibNaive(n - 1) + fibNaive(n - 2);
}

// Memoized helper
function fibMemoizeHelper(n, memo) {
    if (memo[n] !== -1n) return memo[n];
    if (n <= 1) {
        memo[n] = BigInt(n);
        return memo[n];
    }
    memo[n] = fibMemoizeHelper(n - 1, memo) + fibMemoizeHelper(n - 2, memo);
    return memo[n];
}

function fibMemoization(n) {
    const memo = new Array(n + 1).fill(-1n);
    return fibMemoizeHelper(n, memo);
}

function fibTabulation(n) {
    if (n <= 1) return BigInt(n);
    const table = new Array(n + 1);
    table[0] = 0n;
    table[1] = 1n;
    for (let i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}

function main() {
    const n = 35;
    console.log(`Fib(${n}) Naive: ${fibNaive(n).toString()}`);
    console.log(`Fib(${n}) Memo: ${fibMemoization(n).toString()}`);
    console.log(`Fib(${n}) Tab: ${fibTabulation(n).toString()}`);
    console.log();

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Press Enter to exit...", () => {
        rl.close();
    });
}

main();
