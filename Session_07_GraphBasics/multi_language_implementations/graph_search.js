const readline = require('readline');

class Node {
    constructor(dest, next = null) {
        this.dest = dest;
        this.next = next;
    }
}

class List {
    constructor() {
        this.head = null;
    }
}

class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.array = Array.from({ length: vertices }, () => new List());
    }
}

function createGraph(vertices) {
    return new Graph(vertices);
}

function addEdge(graph, src, dest) {
    const node1 = new Node(dest, graph.array[src].head);
    graph.array[src].head = node1;

    const node2 = new Node(src, graph.array[dest].head);
    graph.array[dest].head = node2;
}

function runBFS(graph, startVertex) {
    const visited = Array(graph.V).fill(false);
    const queue = Array(graph.V).fill(0);
    let front = 0;
    let rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    let trace = `BFS Starting from Vertex ${startVertex}: `;

    while (front < rear) {
        const curr = queue[front++];
        trace += curr + " ";

        let temp = graph.array[curr].head;
        while (temp !== null) {
            const adj = temp.dest;
            if (!visited[adj]) {
                visited[adj] = true;
                queue[rear++] = adj;
            }
            temp = temp.next;
        }
    }
    console.log(trace.trim() + " ");
}

function dfsHelper(graph, vertex, visited, traceObj) {
    visited[vertex] = true;
    traceObj.trace += vertex + " ";

    let temp = graph.array[vertex].head;
    while (temp !== null) {
        const adj = temp.dest;
        if (!visited[adj]) {
            dfsHelper(graph, adj, visited, traceObj);
        }
        temp = temp.next;
    }
}

function runDFS(graph, startVertex) {
    const visited = Array(graph.V).fill(false);
    const traceObj = { trace: `DFS Starting from Vertex ${startVertex}: ` };
    dfsHelper(graph, startVertex, visited, traceObj);
    console.log(traceObj.trace.trim() + " ");
}

function main() {
    const numVertices = 5;
    const graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    console.log("=== Graph Search Algorithms ===\n");
    runBFS(graph, 0);
    runDFS(graph, 0);

    console.log();
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Press Enter to exit...", () => {
        rl.close();
    });
}

main();
