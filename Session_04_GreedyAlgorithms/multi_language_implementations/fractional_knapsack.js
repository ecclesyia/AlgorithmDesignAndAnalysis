const readline = require('readline');

function solveFractionalKnapsack(items, capacity) {
    const itemsWithRatio = items.map(item => ({
        ...item,
        ratio: item.value / item.weight
    }));

    const sortedItems = itemsWithRatio.sort((a, b) => b.ratio - a.ratio);
    let totalValue = 0.0;
    let remainingCapacity = capacity;

    for (let item of sortedItems) {
        if (remainingCapacity <= 0) break;
        if (item.weight <= remainingCapacity) {
            remainingCapacity -= item.weight;
            totalValue += item.value;
        } else {
            let fraction = remainingCapacity / item.weight;
            totalValue += item.value * fraction;
            remainingCapacity = 0;
        }
    }
    console.log(`Max Knapsack value: ${totalValue.toFixed(2)}`);
}

function main() {
    const items = [
        {id: 1, value: 60.0, weight: 10.0},
        {id: 2, value: 100.0, weight: 20.0},
        {id: 3, value: 120.0, weight: 30.0}
    ];
    solveFractionalKnapsack(items, 50.0);
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
