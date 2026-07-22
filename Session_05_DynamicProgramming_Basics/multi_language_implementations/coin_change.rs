use std::io::{self, Write};

const INF: i32 = 1e9 as i32;

fn get_min_coins(coins: &[i32], amount: i32) -> i32 {
    let amount_usize = amount as usize;
    let mut dp = vec![INF; amount_usize + 1];
    dp[0] = 0;
    for i in 1..=amount_usize {
        for j in 0..coins.len() {
            if coins[j] as usize <= i {
                let sub_res = dp[i - coins[j] as usize];
                if sub_res != INF && sub_res + 1 < dp[i] {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    let result = dp[amount_usize];
    if result == INF {
        -1
    } else {
        result
    }
}

fn main() {
    let coins = [1, 3, 4];
    let amount = 6;
    println!("Min coins required: {}", get_min_coins(&coins, amount));
    println!();

    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
