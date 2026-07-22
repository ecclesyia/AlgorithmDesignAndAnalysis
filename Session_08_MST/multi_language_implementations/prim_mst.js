const readline = require('readline');

const V = 5;
const INF = 999999;

function minKey(key, mstSet) {
    let min = INF;
    let min_index = -1;

    for (let v = 0; v < V; v++) {
        if (mstSet[v] === false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

function printMST(parent, graph) {
    console.log("Prim's MST Edges:");
    let totalWeight = 0;
    for (let i = 1; i < V; i++) {
        console.log(`  ${parent[i]} - ${i} == ${graph[i][parent[i]]}`);
        totalWeight += graph[i][parent[i]];
    }
    console.log(`Total Cost of MST: ${totalWeight}`);
}

function runPrim(graph) {
    const parent = Array(V).fill(0);
    const key = Array(V).fill(INF);
    const mstSet = Array(V).fill(false);

    key[0] = 0;
    parent[0] = -1;

    for (let count = 0; count < V - 1; count++) {
        const u = minKey(key, mstSet);
        mstSet[u] = true;

        for (let v = 0; v < V; v++) {
            if (graph[u][v] !== 0 && mstSet[v] === false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

function main() {
    const graph = [
        [0, 2, 0, 6, 0],
        [2, 0, 3, 8, 5],
        [0, 3, 0, 0, 7],
        [6, 8, 0, 0, 9],
        [0, 5, 7, 9, 0]
    ];

    console.log("=== Prim's Minimum Spanning Tree ===\n");
    runPrim(graph);

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
