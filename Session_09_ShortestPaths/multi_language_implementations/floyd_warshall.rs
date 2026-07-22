use std::io::{self, BufRead};

const V: usize = 4;
const INF: i32 = 999999;

fn print_matrix(dist: &[[i32; V]; V]) {
    println!("Shortest distances between every pair of vertices:");
    for i in 0..V {
        for j in 0..V {
            if dist[i][j] == INF {
                print!("{:>7}", "INF");
            } else {
                print!("{:>7}", dist[i][j]);
            }
        }
        println!();
    }
}

fn run_floyd_warshall(graph: &[[i32; V]; V]) {
    let mut dist = [[0; V]; V];

    for i in 0..V {
        for j in 0..V {
            dist[i][j] = graph[i][j];
        }
    }

    for k in 0..V {
        for i in 0..V {
            for j in 0..V {
                if dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j] {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    print_matrix(&dist);
}

fn main() {
    let graph = [
        [0, 5, INF, 10],
        [INF, 0, 3, INF],
        [INF, INF, 0, 1],
        [INF, INF, INF, 0],
    ];

    println!("=== Floyd-Warshall All-Pairs Shortest Path ===\n");
    run_floyd_warshall(&graph);

    println!();
    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
