use std::io::{self, Write};

fn print_indent(depth: i32) {
    for _ in 0..depth {
        print!("  |  ");
    }
}

fn calculate_factorial(n: i32, depth: i32) -> i64 {
    print_indent(depth);
    println!("Entering factorial({}). Address of n: {:p}", n, &n);
    if n <= 1 {
        print_indent(depth);
        println!("Base Case reached for factorial({}). Returning 1.", n);
        return 1;
    }
    let sub_result = calculate_factorial(n - 1, depth + 1);
    let result = n as i64 * sub_result;
    print_indent(depth);
    println!("Exiting factorial({}) -> returning {} * {} = {}", n, n, sub_result, result);
    return result;
}

fn calculate_fibonacci(n: i32, depth: i32, branch: &str) -> i32 {
    print_indent(depth);
    println!("Entering fibonacci({}) [{} branch]. Address of n: {:p}", n, branch, &n);
    if n == 0 {
        print_indent(depth);
        println!("Base Case: fibonacci(0) = 0. Returning.");
        return 0;
    }
    if n == 1 {
        print_indent(depth);
        println!("Base Case: fibonacci(1) = 1. Returning.");
        return 1;
    }
    let left = calculate_fibonacci(n - 1, depth + 1, "Left");
    let right = calculate_fibonacci(n - 2, depth + 1, "Right");
    let result = left + right;
    print_indent(depth);
    println!("Exiting fibonacci({}) -> returning {} + {} = {}", n, left, right, result);
    return result;
}

fn main() {
    let val = 5;
    println!("=== Recursion & Stack Frame Visualizer ===\n");
    println!("--- PART 1: Linear Recursion - Factorial({}) ---", val);
    let fact = calculate_factorial(val, 0);
    println!("\nFactorial of {} is: {}\n", val, fact);
    println!("--------------------------------------------------\n");
    println!("--- PART 2: Tree Recursion - Fibonacci(4) ---");
    let fib = calculate_fibonacci(4, 0, "Root");
    println!("\nFibonacci of 4 is: {}\n", fib);
    
    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
