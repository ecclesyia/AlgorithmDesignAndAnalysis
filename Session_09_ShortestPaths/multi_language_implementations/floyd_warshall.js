const readline = require('readline');

const V = 4;
const INF = 999999;

function padLeft(str, length) {
    while (str.length < length) {
        str = " " + str;
    }
    return str;
}

// Replicate "%7s" / "%7d" formatting of C code
function printMatrix(dist) {
    console.log("Shortest distances between every pair of vertices:");
    for (let i = 0; i < V; i++) {
        let row = "";
        for (let j = 0; j < V; j++) {
            if (dist[i][j] === INF) {
                row += padLeft("INF", 7);
            } else {
                row += padLeft(String(dist[i][j]), 7);
            }
        }
        console.log(row);
    }
}

function runFloydWarshall(graph) {
    const dist = Array.from({ length: V }, () => Array(V).fill(0));

    for (let i = 0; i < V; i++) {
        for (let j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (let k = 0; k < V; k++) {
        for (let i = 0; i < V; i++) {
            for (let j = 0; j < V; j++) {
                if (dist[i][k] !== INF && dist[k][j] !== INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printMatrix(dist);
}

function main() {
    const graph = [
        [0, 5, INF, 10],
        [INF, 0, 3, INF],
        [INF, INF, 0, 1],
        [INF, INF, INF, 0]
    ];

    console.log("=== Floyd-Warshall All-Pairs Shortest Path ===\n");
    runFloydWarshall(graph);

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
