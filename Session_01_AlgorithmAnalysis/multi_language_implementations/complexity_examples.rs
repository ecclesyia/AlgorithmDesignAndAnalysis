use std::io::{self, Write};

fn demonstrate_constant_time(n: i32) {
    let mut operations = 0;
    let a = 10;
    operations += 1;
    let b = 20;
    operations += 1;
    let _sum = a + b;
    operations += 1;
    println!("O(1) Constant Time:");
    println!("  Input size (n): {}", n);
    println!("  Actual operations counted: {}\n", operations);
}

fn demonstrate_logarithmic_time(n: i32) {
    let mut operations = 0;
    let mut temp = n;
    println!("O(log n) Logarithmic Time:");
    println!("  Dividing input size {} by 2 repeatedly:", n);
    while temp > 1 {
        println!("    Current value: {}", temp);
        temp /= 2;
        operations += 1;
    }
    println!("  Input size (n): {}", n);
    println!("  Actual operations counted: {}\n", operations);
}

fn demonstrate_linear_time(n: i32) {
    let mut operations = 0;
    for _ in 0..n {
        operations += 1;
    }
    println!("O(n) Linear Time:");
    println!("  Input size (n): {}", n);
    println!("  Actual operations counted: {}\n", operations);
}

fn demonstrate_linearithmic_time(n: i32) {
    let mut operations = 0;
    for _ in 0..n {
        let mut temp = n;
        while temp > 1 {
            temp /= 2;
            operations += 1;
        }
    }
    println!("O(n log n) Linearithmic Time:");
    println!("  Input size (n): {}", n);
    println!("  Actual operations counted: {}\n", operations);
}

fn demonstrate_quadratic_time(n: i32) {
    let mut operations = 0;
    for _ in 0..n {
        for _ in 0..n {
            operations += 1;
        }
    }
    println!("O(n^2) Quadratic Time:");
    println!("  Input size (n): {}", n);
    println!("  Actual operations counted: {} (n * n)\n", operations);
}

fn main() {
    let n = 16;
    println!("=== Time Complexity Visualizer ===");
    println!("This program counts operations to demonstrate theoretical time complexities.\n");
    demonstrate_constant_time(n);
    demonstrate_logarithmic_time(n);
    demonstrate_linear_time(n);
    demonstrate_linearithmic_time(n);
    demonstrate_quadratic_time(n);
    
    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
