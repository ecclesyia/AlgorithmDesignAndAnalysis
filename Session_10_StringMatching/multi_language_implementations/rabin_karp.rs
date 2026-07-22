use std::io::{self, BufRead};

const D: i32 = 256;
const Q: i32 = 101;

fn run_rabin_karp(pat: &str, txt: &str) {
    let pat_bytes = pat.as_bytes();
    let txt_bytes = txt.as_bytes();
    let m = pat_bytes.len();
    let n = txt_bytes.len();
    
    let mut p = 0;
    let mut t = 0;
    let mut h = 1;
    
    for _ in 0..m - 1 {
        h = (h * D) % Q;
    }
    
    for i in 0..m {
        p = (D * p + pat_bytes[i] as i32) % Q;
        t = (D * t + txt_bytes[i] as i32) % Q;
    }
    
    println!("Rabin-Karp Search details:");
    println!("  Pattern hash: {}", p);
    
    for i in 0..=n - m {
        if p == t {
            println!("  Hash match found at index {} (hash: {}). Checking characters...", i, t);
            
            let mut j = 0;
            while j < m {
                if txt_bytes[i + j] != pat_bytes[j] {
                    break;
                }
                j += 1;
            }
            if j == m {
                println!("    Pattern found at index: {}", i);
            }
        }
        
        if i < n - m {
            t = (D * (t - txt_bytes[i] as i32 * h) + txt_bytes[i + m] as i32) % Q;
            if t < 0 {
                t += Q;
            }
        }
    }
}

fn main() {
    let txt = "GEEKS FOR GEEKS";
    let pat = "GEEK";
    
    println!("=== Rabin-Karp String Search ===");
    println!("Text: \"{}\"", txt);
    println!("Pattern: \"{}\"\n", pat);
    
    run_rabin_karp(pat, txt);
    
    println!();
    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
