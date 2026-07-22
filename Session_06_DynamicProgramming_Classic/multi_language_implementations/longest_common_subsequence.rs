use std::io::{self, Write};
use std::cmp::max;

fn solve_lcs(s1: &str, s2: &str) {
    let chars1: Vec<char> = s1.chars().collect();
    let chars2: Vec<char> = s2.chars().collect();
    let m = chars1.len();
    let n = chars2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];

    for i in 0..=m {
        for j in 0..=n {
            if i == 0 || j == 0 {
                dp[i][j] = 0;
            } else if chars1[i - 1] == chars2[j - 1] {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    println!("LCS Length: {}", dp[m][n]);

    let mut index = dp[m][n];
    let mut lcs_str = vec![' '; index];
    let mut i = m;
    let mut j = n;
    while i > 0 && j > 0 {
        if chars1[i - 1] == chars2[j - 1] {
            lcs_str[index - 1] = chars1[i - 1];
            i -= 1;
            j -= 1;
            index -= 1;
        } else if dp[i - 1][j] > dp[i][j - 1] {
            i -= 1;
        } else {
            j -= 1;
        }
    }
    let lcs_string: String = lcs_str.into_iter().collect();
    println!("LCS String: {}", lcs_string);
}

fn main() {
    let s1 = "STONE";
    let s2 = "LONEST";
    solve_lcs(s1, s2);
    println!();

    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
