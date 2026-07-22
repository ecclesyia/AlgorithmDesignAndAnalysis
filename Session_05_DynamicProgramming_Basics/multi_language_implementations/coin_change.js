const readline = require('readline');

const INF = 1e9;

function getMinCoins(coins, amount) {
    const dp = new Array(amount + 1).fill(INF);
    dp[0] = 0;
    for (let i = 1; i <= amount; i++) {
        for (let j = 0; j < coins.length; j++) {
            if (coins[j] <= i) {
                const subRes = dp[i - coins[j]];
                if (subRes !== INF && subRes + 1 < dp[i]) {
                    dp[i] = subRes + 1;
                }
            }
        }
    }
    const result = dp[amount];
    return result === INF ? -1 : result;
}

function main() {
    const coins = [1, 3, 4];
    const amount = 6;
    console.log(`Min coins required: ${getMinCoins(coins, amount)}`);
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
