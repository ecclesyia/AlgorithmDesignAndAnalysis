const readline = require('readline');

function solveKnapsack(weights, values, n, W) {
    const dp = Array.from({ length: n + 1 }, () => new Array(W + 1).fill(0));
    for (let i = 0; i <= n; i++) {
        for (let w = 0; w <= W; w++) {
            if (i === 0 || w === 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = Math.max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    console.log(`Max Knapsack value: ${dp[n][W]}`);
    let w = W;
    for (let i = n; i > 0; i--) {
        if (dp[i][w] !== dp[i - 1][w]) {
            console.log(`  Selected: Item ID ${i} (Val: ${values[i - 1]}, Wt: ${weights[i - 1]})`);
            w -= weights[i - 1];
        }
    }
}

function main() {
    const values = [60, 100, 120];
    const weights = [10, 20, 30];
    solveKnapsack(weights, values, 3, 50);
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
