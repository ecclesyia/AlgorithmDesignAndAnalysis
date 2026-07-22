use std::io::{self, BufRead};

const V: usize = 5;
const INF: i32 = 999999;

fn min_key(key: &[i32; V], mst_set: &[bool; V]) -> usize {
    let mut min = INF;
    let mut min_index = 0;

    for v in 0..V {
        if !mst_set[v] && key[v] < min {
            min = key[v];
            min_index = v;
        }
    }
    min_index
}

fn print_mst(parent: &[i32; V], graph: &[[i32; V]; V]) {
    println!("Prim's MST Edges:");
    let mut total_weight = 0;
    for i in 1..V {
        let p = parent[i] as usize;
        println!("  {} - {} == {}", p, i, graph[i][p]);
        total_weight += graph[i][p];
    }
    println!("Total Cost of MST: {}", total_weight);
}

fn run_prim(graph: &[[i32; V]; V]) {
    let mut parent = [0; V];
    let mut key = [INF; V];
    let mut mst_set = [false; V];

    key[0] = 0;
    parent[0] = -1;

    for _ in 0..V - 1 {
        let u = min_key(&key, &mst_set);
        mst_set[u] = true;

        for v in 0..V {
            if graph[u][v] != 0 && !mst_set[v] && graph[u][v] < key[v] {
                parent[v] = u as i32;
                key[v] = graph[u][v];
            }
        }
    }

    print_mst(&parent, graph);
}

fn main() {
    let graph = [
        [0, 2, 0, 6, 0],
        [2, 0, 3, 8, 5],
        [0, 3, 0, 0, 7],
        [6, 8, 0, 0, 9],
        [0, 5, 7, 9, 0],
    ];

    println!("=== Prim's Minimum Spanning Tree ===\n");
    run_prim(&graph);

    println!();
    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
