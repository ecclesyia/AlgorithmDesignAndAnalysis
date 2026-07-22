const readline = require('readline');

class Node {
    constructor(level = 0, profit = 0, weight = 0, bound = 0.0) {
        this.level = level;
        this.profit = profit;
        this.weight = weight;
        this.bound = bound;
    }
}

class Item {
    constructor(id, weight, value) {
        this.id = id;
        this.weight = weight;
        this.value = value;
    }
}

function calculateBound(u, n, W, items) {
    if (u.weight >= W) {
        return 0;
    }

    let profit_bound = u.profit;
    let j = u.level + 1;
    let total_weight = u.weight;

    while (j < n && total_weight + items[j].weight <= W) {
        total_weight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }

    if (j < n) {
        profit_bound += (W - total_weight) * (items[j].value / items[j].weight);
    }

    return profit_bound;
}

function solveKnapsackBB(W, items, n) {
    // Sort items by ratio descending
    items.sort((a, b) => {
        const r1 = a.value / a.weight;
        const r2 = b.value / b.weight;
        return r2 - r1;
    });

    const q = [];

    const u = new Node(-1, 0, 0, 0.0);
    u.bound = calculateBound(u, n, W, items);

    let maxProfit = 0;
    q.push(u);

    console.log("Branch and Bound Search Steps:");

    while (q.length > 0) {
        const currU = q.shift();

        const v = new Node();
        if (currU.level === -1) {
            v.level = 0;
        } else if (currU.level === n - 1) {
            continue;
        } else {
            v.level = currU.level + 1;
        }

        // --- BRANCH 1: Include next item ---
        v.weight = currU.weight + items[v.level].weight;
        v.profit = currU.profit + items[v.level].value;

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
            console.log(`  Updated max profit to: ${maxProfit} (Level ${v.level}, Weight ${v.weight})`);
        }

        v.bound = calculateBound(v, n, W, items);

        if (v.bound > maxProfit) {
            q.push(v);
            console.log(`    Branch WITH item ${items[v.level].id} enqueued. Bound = ${v.bound.toFixed(2)}`);
        } else {
            console.log(`    Branch WITH item ${items[v.level].id} pruned. Bound (${v.bound.toFixed(2)}) <= MaxProfit (${maxProfit})`);
        }

        // --- BRANCH 2: Exclude next item ---
        const vExclude = new Node(v.level, currU.profit, currU.weight, 0.0);
        vExclude.bound = calculateBound(vExclude, n, W, items);

        if (vExclude.bound > maxProfit) {
            q.push(vExclude);
            console.log(`    Branch WITHOUT item ${items[v.level].id} enqueued. Bound = ${vExclude.bound.toFixed(2)}`);
        } else {
            console.log(`    Branch WITHOUT item ${items[v.level].id} pruned. Bound (${vExclude.bound.toFixed(2)}) <= MaxProfit (${maxProfit})`);
        }
    }

    return maxProfit;
}

function main() {
    const W = 10;
    const items = [
        new Item(1, 2, 40),
        new Item(2, 5, 30),
        new Item(3, 10, 50),
        new Item(4, 5, 10)
    ];
    const n = items.length;

    console.log("=== Branch and Bound: 0/1 Knapsack ===");
    console.log(`Capacity: ${W}\n`);

    const maxProfit = solveKnapsackBB(W, items, n);

    console.log(`\nMaximum Profit: ${maxProfit}`);

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
