use std::io::{self, BufRead};

const N: usize = 4;

fn print_board(board: &[[i32; N]; N]) {
    for i in 0..N {
        for j in 0..N {
            if board[i][j] == 1 {
                print!(" Q ");
            } else {
                print!(" . ");
            }
        }
        println!();
    }
    println!();
}

fn is_safe(board: &[[i32; N]; N], row: usize, col: usize) -> bool {
    // Check this row on left side
    for i in 0..col {
        if board[row][i] == 1 {
            return false;
        }
    }

    // Check upper diagonal on left side
    let mut i = row as i32;
    let mut j = col as i32;
    while i >= 0 && j >= 0 {
        if board[i as usize][j as usize] == 1 {
            return false;
        }
        i -= 1;
        j -= 1;
    }

    // Check lower diagonal on left side
    let mut i = row as i32;
    let mut j = col as i32;
    while j >= 0 && i < N as i32 {
        if board[i as usize][j as usize] == 1 {
            return false;
        }
        i += 1;
        j -= 1;
    }

    true
}

fn solve_n_queens_helper(board: &mut [[i32; N]; N], col: usize) -> bool {
    if col >= N {
        return true;
    }

    for i in 0..N {
        if is_safe(board, i, col) {
            board[i][col] = 1;

            println!("Trying placement at Row {}, Col {}:", i, col);
            print_board(board);

            if solve_n_queens_helper(board, col + 1) {
                return true;
            }

            board[i][col] = 0;
            println!("Backtracking: Removed Queen from Row {}, Col {}\n", i, col);
        }
    }

    false
}

fn solve_n_queens() {
    let mut board = [[0; N]; N];

    if !solve_n_queens_helper(&mut board, 0) {
        println!("Solution does not exist");
        return;
    }

    println!("=== Final Solution Found ===");
    print_board(&board);
}

fn main() {
    println!("=== Backtracking: N-Queens Solver (N = {}) ===\n", N);
    solve_n_queens();

    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
