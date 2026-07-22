const readline = require('readline');

const V = 4;

function createAdjacencyMatrix(adjMatrix) {
    for (let i = 0; i < V; i++) {
        for (let j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[3][0] = 1;
}

function printAdjacencyMatrix(adjMatrix) {
    console.log("Adjacency Matrix:");
    for (let i = 0; i < V; i++) {
        let row = "";
        for (let j = 0; j < V; j++) {
            row += adjMatrix[i][j] + " ";
        }
        console.log(row.trim() + " ");
    }
    console.log();
}

class AdjListNode {
    constructor(dest) {
        this.dest = dest;
        this.next = null;
    }
}

class AdjList {
    constructor() {
        this.head = null;
    }
}

class Graph {
    constructor(numVertices) {
        this.numVertices = numVertices;
        this.array = Array.from({ length: numVertices }, () => new AdjList());
    }
}

function addEdge(graph, src, dest) {
    const newNode = new AdjListNode(dest);
    newNode.next = graph.array[src].head;
    graph.array[src].head = newNode;
}

function printGraphList(graph) {
    console.log("Adjacency List:");
    for (let v = 0; v < graph.numVertices; v++) {
        let curr = graph.array[v].head;
        let line = `  Vertex ${v}: `;
        while (curr !== null) {
            line += `-> ${curr.dest} `;
            curr = curr.next;
        }
        line += "-> NULL";
        console.log(line);
    }
    console.log();
}

function main() {
    console.log("=== Graph Representations in JavaScript ===\n");

    const adjMatrix = Array.from({ length: V }, () => Array(V).fill(0));
    createAdjacencyMatrix(adjMatrix);
    printAdjacencyMatrix(adjMatrix);

    const graph = new Graph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 0);
    printGraphList(graph);

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Press Enter to exit...", () => {
        rl.close();
    });
}

main();
