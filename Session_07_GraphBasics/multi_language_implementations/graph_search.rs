use std::io::{self, BufRead};

struct Node {
    dest: usize,
    next: Option<Box<Node>>,
}

struct List {
    head: Option<Box<Node>>,
}

struct Graph {
    v: usize,
    array: Vec<List>,
}

fn create_graph(vertices: usize) -> Graph {
    let mut array = Vec::with_capacity(vertices);
    for _ in 0..vertices {
        array.push(List { head: None });
    }
    Graph { v: vertices, array }
}

fn add_edge(graph: &mut Graph, src: usize, dest: usize) {
    let old_head1 = graph.array[src].head.take();
    graph.array[src].head = Some(Box::new(Node {
        dest,
        next: old_head1,
    }));

    let old_head2 = graph.array[dest].head.take();
    graph.array[dest].head = Some(Box::new(Node {
        dest: src,
        next: old_head2,
    }));
}

fn run_bfs(graph: &Graph, start_vertex: usize) {
    let mut visited = vec![false; graph.v];
    let mut queue = vec![0; graph.v];
    let mut front = 0;
    let mut rear = 0;

    visited[start_vertex] = true;
    queue[rear] = start_vertex;
    rear += 1;

    print!("BFS Starting from Vertex {}: ", start_vertex);

    while front < rear {
        let curr = queue[front];
        front += 1;
        print!("{} ", curr);

        let mut temp = &graph.array[curr].head;
        while let Some(node) = temp {
            let adj = node.dest;
            if !visited[adj] {
                visited[adj] = true;
                queue[rear] = adj;
                rear += 1;
            }
            temp = &node.next;
        }
    }
    println!();
}

fn dfs_helper(graph: &Graph, vertex: usize, visited: &mut Vec<bool>) {
    visited[vertex] = true;
    print!("{} ", vertex);

    let mut temp = &graph.array[vertex].head;
    while let Some(node) = temp {
        let adj = node.dest;
        if !visited[adj] {
            dfs_helper(graph, adj, visited);
        }
        temp = &node.next;
    }
}

fn run_dfs(graph: &Graph, start_vertex: usize) {
    let mut visited = vec![false; graph.v];
    print!("DFS Starting from Vertex {}: ", start_vertex);
    dfs_helper(graph, start_vertex, &mut visited);
    println!();
}

fn main() {
    let num_vertices = 5;
    let mut graph = create_graph(num_vertices);

    add_edge(&mut graph, 0, 1);
    add_edge(&mut graph, 0, 2);
    add_edge(&mut graph, 1, 2);
    add_edge(&mut graph, 1, 3);
    add_edge(&mut graph, 2, 4);

    println!("=== Graph Search Algorithms ===\n");
    run_bfs(&graph, 0);
    run_dfs(&graph, 0);

    println!();
    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
