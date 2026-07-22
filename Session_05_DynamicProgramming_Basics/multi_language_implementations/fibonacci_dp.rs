use std::io::{self, Write};

fn fib_naive(n: i32) -> i64 {
    if n <= 1 {
        return n as i64;
    }
    return fib_naive(n - 1) + fib_naive(n - 2);
}

fn fib_memoize_helper(n: usize, memo: &mut [i64]) -> i64 {
    if memo[n] != -1 {
        return memo[n];
    }
    if n <= 1 {
        memo[n] = n as i64;
        return memo[n];
    }
    memo[n] = fib_memoize_helper(n - 1, memo) + fib_memoize_helper(n - 2, memo);
    return memo[n];
}

fn fib_memoization(n: i32) -> i64 {
    let mut memo = vec![-1; (n + 1) as usize];
    return fib_memoize_helper(n as usize, &mut memo);
}

fn fib_tabulation(n: i32) -> i64 {
    if n <= 1 {
        return n as i64;
    }
    let n_usize = n as usize;
    let mut table = vec![0; n_usize + 1];
    table[0] = 0;
    table[1] = 1;
    for i in 2..=n_usize {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n_usize];
}

fn main() {
    let n = 35;
    println!("Fib({}) Naive: {}", n, fib_naive(n));
    println!("Fib({}) Memo: {}", n, fib_memoization(n));
    println!("Fib({}) Tab: {}", n, fib_tabulation(n));
    println!();

    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
