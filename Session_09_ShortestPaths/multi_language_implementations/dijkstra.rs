use std::io::{self, BufRead};

const V: usize = 9;
const INF: i32 = 999999;

fn min_distance(dist: &[i32; V], spt_set: &[bool; V]) -> usize {
    let mut min = INF;
    let mut min_index = 0;

    for v in 0..V {
        if !spt_set[v] && dist[v] <= min {
            min = dist[v];
            min_index = v;
        }
    }
    min_index
}

fn print_solution(dist: &[i32; V]) {
    println!("Vertex \t Distance from Source");
    for i in 0..V {
        if dist[i] == INF {
            println!("{} \t INF", i);
        } else {
            println!("{} \t {}", i, dist[i]);
        }
    }
}

fn run_dijkstra(graph: &[[i32; V]; V], src: usize) {
    let mut dist = [INF; V];
    let mut spt_set = [false; V];

    dist[src] = 0;

    for _ in 0..V - 1 {
        let u = min_distance(&dist, &spt_set);
        spt_set[u] = true;

        for v in 0..V {
            if !spt_set[v]
                && graph[u][v] != 0
                && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print_solution(&dist);
}

fn main() {
    let graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0],
    ];

    println!("=== Dijkstra's Single-Source Shortest Path ===");
    println!("Starting from Source Vertex: 0\n");
    run_dijkstra(&graph, 0);

    println!();
    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
