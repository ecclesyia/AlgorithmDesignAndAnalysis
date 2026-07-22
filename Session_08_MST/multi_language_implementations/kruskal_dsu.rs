use std::io::{self, BufRead};

#[derive(Clone, Copy)]
struct Edge {
    src: usize,
    dest: usize,
    weight: i32,
}

struct Graph {
    v: usize,
    e: usize,
    edges: Vec<Edge>,
}

struct Subset {
    parent: usize,
    rank: usize,
}

fn find(subsets: &mut [Subset], i: usize) -> usize {
    if subsets[i].parent != i {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    subsets[i].parent
}

fn union(subsets: &mut [Subset], x: usize, y: usize) {
    let xroot = find(subsets, x);
    let yroot = find(subsets, y);

    if subsets[xroot].rank < subsets[yroot].rank {
        subsets[xroot].parent = yroot;
    } else if subsets[xroot].rank > subsets[yroot].rank {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank += 1;
    }
}

fn run_kruskal(graph: &mut Graph) {
    let v = graph.v;
    let mut result = Vec::new();
    let mut e = 0;
    let mut i = 0;

    // Sort edges
    graph.edges.sort_by_key(|k| k.weight);

    let mut subsets = Vec::with_capacity(v);
    for idx in 0..v {
        subsets.push(Subset {
            parent: idx,
            rank: 0,
        });
    }

    println!("Kruskal's Edge Evaluation:");

    while e < v - 1 && i < graph.e {
        let next_edge = graph.edges[i];
        i += 1;

        let x = find(&mut subsets, next_edge.src);
        let y = find(&mut subsets, next_edge.dest);

        if x != y {
            result.push(next_edge);
            e += 1;
            union(&mut subsets, x, y);
            println!(
                "  Accepted edge: {} - {} (weight: {})",
                next_edge.src, next_edge.dest, next_edge.weight
            );
        } else {
            println!(
                "  Rejected edge: {} - {} (weight: {}) -> forms a cycle",
                next_edge.src, next_edge.dest, next_edge.weight
            );
        }
    }

    println!("\nFinal Minimum Spanning Tree Edges:");
    let mut minimum_cost = 0;
    for idx in 0..e {
        println!(
            "  {} - {} == {}",
            result[idx].src, result[idx].dest, result[idx].weight
        );
        minimum_cost += result[idx].weight;
    }
    println!("Total Cost of MST: {}", minimum_cost);
}

fn main() {
    let v = 4;
    let e = 5;
    let mut graph = Graph {
        v,
        e,
        edges: Vec::new(),
    };

    graph.edges.push(Edge { src: 0, dest: 1, weight: 10 });
    graph.edges.push(Edge { src: 0, dest: 2, weight: 6 });
    graph.edges.push(Edge { src: 0, dest: 3, weight: 5 });
    graph.edges.push(Edge { src: 1, dest: 3, weight: 15 });
    graph.edges.push(Edge { src: 2, dest: 3, weight: 4 });

    println!("=== Kruskal's Minimum Spanning Tree ===\n");
    run_kruskal(&mut graph);

    println!();
    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
