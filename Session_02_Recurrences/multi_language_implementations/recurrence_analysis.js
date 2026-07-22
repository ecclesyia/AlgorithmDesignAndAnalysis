const readline = require('readline');

function printIndent(depth) {
    process.stdout.write("  |  ".repeat(depth));
}

function getSimulatedAddress(depth) {
    const baseAddress = 0x7ffd5eb3a000;
    const offset = depth * 0x30;
    return "0x" + (baseAddress - offset).toString(16);
}

// Factorial function
function calculateFactorial(n, depth) {
    printIndent(depth);
    const address = getSimulatedAddress(depth);
    console.log(`Entering factorial(${n}). Address of n: ${address}`);
    if (n <= 1) {
        printIndent(depth);
        console.log(`Base Case reached for factorial(${n}). Returning 1.`);
        return 1n;
    }
    const subResult = calculateFactorial(n - 1, depth + 1);
    const result = BigInt(n) * subResult;
    printIndent(depth);
    console.log(`Exiting factorial(${n}) -> returning ${n} * ${subResult} = ${result}`);
    return result;
}

// Fibonacci function
function calculateFibonacci(n, depth, branch) {
    printIndent(depth);
    const address = getSimulatedAddress(depth + 10);
    console.log(`Entering fibonacci(${n}) [${branch} branch]. Address of n: ${address}`);
    if (n === 0) {
        printIndent(depth);
        console.log("Base Case: fibonacci(0) = 0. Returning.");
        return 0;
    }
    if (n === 1) {
        printIndent(depth);
        console.log("Base Case: fibonacci(1) = 1. Returning.");
        return 1;
    }
    const left = calculateFibonacci(n - 1, depth + 1, "Left");
    const right = calculateFibonacci(n - 2, depth + 1, "Right");
    const result = left + right;
    printIndent(depth);
    console.log(`Exiting fibonacci(${n}) -> returning ${left} + ${right} = ${result}`);
    return result;
}

function main() {
    const val = 5;
    console.log("=== Recursion & Stack Frame Visualizer ===\n");
    console.log(`--- PART 1: Linear Recursion - Factorial(${val}) ---`);
    const fact = calculateFactorial(val, 0);
    console.log(`\nFactorial of ${val} is: ${fact}\n`);
    console.log("--------------------------------------------------\n");
    console.log("--- PART 2: Tree Recursion - Fibonacci(4) ---");
    const fib = calculateFibonacci(4, 0, "Root");
    console.log(`\nFibonacci of 4 is: ${fib}\n`);
    
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Press Enter to exit...", () => {
        rl.close();
    });
}

main();
