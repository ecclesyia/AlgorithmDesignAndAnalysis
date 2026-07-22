const readline = require('readline');

const V = 9;
const INF = 999999;

function minDistance(dist, sptSet) {
    let min = INF;
    let min_index = -1;

    for (let v = 0; v < V; v++) {
        if (sptSet[v] === false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

function printSolution(dist) {
    console.log("Vertex \t Distance from Source");
    for (let i = 0; i < V; i++) {
        if (dist[i] === INF) {
            console.log(`${i} \t INF`);
        } else {
            console.log(`${i} \t ${dist[i]}`);
        }
    }
}

function runDijkstra(graph, src) {
    const dist = Array(V).fill(INF);
    const sptSet = Array(V).fill(false);

    dist[src] = 0;

    for (let count = 0; count < V - 1; count++) {
        const u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (let v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] !== 0 && dist[u] !== INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

function main() {
    const graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ];

    console.log("=== Dijkstra's Single-Source Shortest Path ===");
    console.log("Starting from Source Vertex: 0\n");
    runDijkstra(graph, 0);

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
