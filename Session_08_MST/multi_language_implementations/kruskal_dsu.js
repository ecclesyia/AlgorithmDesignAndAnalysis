const readline = require('readline');

class Edge {
    constructor(src, dest, weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }
}

class Graph {
    constructor(V, E) {
        this.V = V;
        this.E = E;
        this.edges = [];
    }
}

class Subset {
    constructor(parent, rank) {
        this.parent = parent;
        this.rank = rank;
    }
}

function find(subsets, i) {
    if (subsets[i].parent !== i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

function union(subsets, x, y) {
    const xroot = find(subsets, x);
    const yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

function runKruskal(graph) {
    const V = graph.V;
    const result = [];
    let e = 0;
    let i = 0;

    // Sort edges
    graph.edges.sort((a, b) => a.weight - b.weight);

    const subsets = [];
    for (let v = 0; v < V; v++) {
        subsets.push(new Subset(v, 0));
    }

    console.log("Kruskal's Edge Evaluation:");

    while (e < V - 1 && i < graph.E) {
        const nextEdge = graph.edges[i++];

        const x = find(subsets, nextEdge.src);
        const y = find(subsets, nextEdge.dest);

        if (x !== y) {
            result.push(nextEdge);
            e++;
            union(subsets, x, y);
            console.log(`  Accepted edge: ${nextEdge.src} - ${nextEdge.dest} (weight: ${nextEdge.weight})`);
        } else {
            console.log(`  Rejected edge: ${nextEdge.src} - ${nextEdge.dest} (weight: ${nextEdge.weight}) -> forms a cycle`);
        }
    }

    console.log("\nFinal Minimum Spanning Tree Edges:");
    let minimumCost = 0;
    for (let idx = 0; idx < e; idx++) {
        console.log(`  ${result[idx].src} - ${result[idx].dest} == ${result[idx].weight}`);
        minimumCost += result[idx].weight;
    }
    console.log(`Total Cost of MST: ${minimumCost}`);
}

function main() {
    const V = 4;
    const E = 5;
    const graph = new Graph(V, E);

    graph.edges.push(new Edge(0, 1, 10));
    graph.edges.push(new Edge(0, 2, 6));
    graph.edges.push(new Edge(0, 3, 5));
    graph.edges.push(new Edge(1, 3, 15));
    graph.edges.push(new Edge(2, 3, 4));

    console.log("=== Kruskal's Minimum Spanning Tree ===\n");
    runKruskal(graph);

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
