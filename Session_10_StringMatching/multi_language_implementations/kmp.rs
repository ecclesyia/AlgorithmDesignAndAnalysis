use std::io::{self, BufRead};

fn compute_lps_array(pat: &str, m: usize, lps: &mut [usize]) {
    let pat_bytes = pat.as_bytes();
    let mut len_prev = 0;
    lps[0] = 0;
    let mut i = 1;

    while i < m {
        if pat_bytes[i] == pat_bytes[len_prev] {
            len_prev += 1;
            lps[i] = len_prev;
            i += 1;
        } else {
            if len_prev != 0 {
                len_prev = lps[len_prev - 1];
            } else {
                lps[i] = 0;
                i += 1;
            }
        }
    }
}

fn run_kmp(pat: &str, txt: &str) {
    let pat_bytes = pat.as_bytes();
    let txt_bytes = txt.as_bytes();
    let m = pat_bytes.len();
    let n = txt_bytes.len();
    
    let mut lps = vec![0; m];
    compute_lps_array(pat, m, &mut lps);

    println!("Precomputed LPS Table for pattern \"{}\":", pat);
    print!("  Char: ");
    for i in 0..m {
        print!("{} ", pat_bytes[i] as char);
    }
    println!();
    print!("  LPS:  ");
    for i in 0..m {
        print!("{} ", lps[i]);
    }
    println!("\n");

    let mut i = 0;
    let mut j = 0;

    println!("KMP Search steps:");
    while (n - i) >= (m - j) {
        if pat_bytes[j] == txt_bytes[i] {
            i += 1;
            j += 1;
        }

        if j == m {
            println!("  Pattern found at index: {}", i - j);
            j = lps[j - 1];
        } else if i < n && pat_bytes[j] != txt_bytes[i] {
            if j != 0 {
                println!(
                    "  Mismatch at txt[{}] ('{}') and pat[{}] ('{}'). Sliding to pat[{}]",
                    i, txt_bytes[i] as char, j, pat_bytes[j] as char, lps[j - 1]
                );
                j = lps[j - 1];
            } else {
                i += 1;
            }
        }
    }
}

fn main() {
    let txt = "ABABDABACDABABCABAB";
    let pat = "ABABCABAB";

    println!("=== Knuth-Morris-Pratt (KMP) Search ===");
    println!("Text: \"{}\"", txt);
    println!("Pattern: \"{}\"\n", pat);

    run_kmp(pat, txt);

    println!();
    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
