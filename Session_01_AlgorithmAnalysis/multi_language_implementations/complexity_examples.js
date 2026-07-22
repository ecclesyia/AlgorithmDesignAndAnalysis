const readline = require('readline');

function demonstrateConstantTime(n) {
    let operations = 0;
    let a = 10;
    operations++;
    let b = 20;
    operations++;
    let sum = a + b;
    operations++;
    console.log("O(1) Constant Time:");
    console.log(`  Input size (n): ${n}`);
    console.log(`  Actual operations counted: ${operations}\n`);
}

function demonstrateLogarithmicTime(n) {
    let operations = 0;
    let temp = n;
    console.log("O(log n) Logarithmic Time:");
    console.log(`  Dividing input size ${n} by 2 repeatedly:`);
    while (temp > 1) {
        console.log(`    Current value: ${temp}`);
        temp = Math.floor(temp / 2);
        operations++;
    }
    console.log(`  Input size (n): ${n}`);
    console.log(`  Actual operations counted: ${operations}\n`);
}

function demonstrateLinearTime(n) {
    let operations = 0;
    for (let i = 0; i < n; i++) {
        operations++;
    }
    console.log("O(n) Linear Time:");
    console.log(`  Input size (n): ${n}`);
    console.log(`  Actual operations counted: ${operations}\n`);
}

function demonstrateLinearithmicTime(n) {
    let operations = 0;
    for (let i = 0; i < n; i++) {
        let temp = n;
        while (temp > 1) {
            temp = Math.floor(temp / 2);
            operations++;
        }
    }
    console.log("O(n log n) Linearithmic Time:");
    console.log(`  Input size (n): ${n}`);
    console.log(`  Actual operations counted: ${operations}\n`);
}

function demonstrateQuadraticTime(n) {
    let operations = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            operations++;
        }
    }
    console.log("O(n^2) Quadratic Time:");
    console.log(`  Input size (n): ${n}`);
    console.log(`  Actual operations counted: ${operations} (n * n)\n`);
}

function main() {
    let n = 16;
    console.log("=== Time Complexity Visualizer ===");
    console.log("This program counts operations to demonstrate theoretical time complexities.\n");
    demonstrateConstantTime(n);
    demonstrateLogarithmicTime(n);
    demonstrateLinearTime(n);
    demonstrateLinearithmicTime(n);
    demonstrateQuadraticTime(n);
    
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Press Enter to exit...", () => {
        rl.close();
    });
}

main();
