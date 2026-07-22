use std::io::{self, Write};
use std::cmp::max;

fn solve_knapsack(weights: &[i32], values: &[i32], n: usize, w_capacity: usize) {
    let mut dp = vec![vec![0; w_capacity + 1]; n + 1];
    for i in 0..=n {
        for w in 0..=w_capacity {
            if i == 0 || w == 0 {
                dp[i][w] = 0;
            } else if weights[i - 1] as usize <= w {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1] as usize]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    println!("Max Knapsack value: {}", dp[n][w_capacity]);
    let mut w = w_capacity;
    for i in (1..=n).rev() {
        if dp[i][w] != dp[i - 1][w] {
            println!("  Selected: Item ID {} (Val: {}, Wt: {})", i, values[i - 1], weights[i - 1]);
            w -= weights[i - 1] as usize;
        }
    }
}

fn main() {
    let values = [60, 100, 120];
    let weights = [10, 20, 30];
    solve_knapsack(&weights, &values, 3, 50);
    println!();

    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
