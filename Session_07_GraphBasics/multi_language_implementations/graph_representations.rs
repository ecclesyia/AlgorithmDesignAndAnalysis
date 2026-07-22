use std::io::{self, BufRead};

const V: usize = 4;

fn create_adjacency_matrix(adj_matrix: &mut [[i32; V]; V]) {
    for i in 0..V {
        for j in 0..V {
            adj_matrix[i][j] = 0;
        }
    }
    adj_matrix[0][1] = 1;
    adj_matrix[0][2] = 1;
    adj_matrix[1][3] = 1;
    adj_matrix[3][0] = 1;
}

fn print_adjacency_matrix(adj_matrix: &[[i32; V]; V]) {
    println!("Adjacency Matrix:");
    for i in 0..V {
        for j in 0..V {
            print!("{} ", adj_matrix[i][j]);
        }
        println!();
    }
    println!();
}

struct AdjListNode {
    dest: usize,
    next: Option<Box<AdjListNode>>,
}

struct AdjList {
    head: Option<Box<AdjListNode>>,
}

struct Graph {
    num_vertices: usize,
    array: Vec<AdjList>,
}

fn create_graph(num_vertices: usize) -> Graph {
    let mut array = Vec::with_capacity(num_vertices);
    for _ in 0..num_vertices {
        array.push(AdjList { head: None });
    }
    Graph {
        num_vertices,
        array,
    }
}

fn add_edge(graph: &mut Graph, src: usize, dest: usize) {
    let old_head = graph.array[src].head.take();
    let new_node = Box::new(AdjListNode {
        dest,
        next: old_head,
    });
    graph.array[src].head = Some(new_node);
}

fn print_graph_list(graph: &Graph) {
    println!("Adjacency List:");
    for v in 0..graph.num_vertices {
        print!("  Vertex {}: ", v);
        let mut curr = &graph.array[v].head;
        while let Some(node) = curr {
            print!("-> {} ", node.dest);
            curr = &node.next;
        }
        println!("-> NULL");
    }
    println!();
}

fn main() {
    println!("=== Graph Representations in Rust ===\n");

    let mut adj_matrix = [[0; V]; V];
    create_adjacency_matrix(&mut adj_matrix);
    print_adjacency_matrix(&adj_matrix);

    let mut graph = create_graph(V);
    add_edge(&mut graph, 0, 1);
    add_edge(&mut graph, 0, 2);
    add_edge(&mut graph, 1, 3);
    add_edge(&mut graph, 3, 0);
    print_graph_list(&graph);

    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
