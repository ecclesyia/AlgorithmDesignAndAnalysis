import Foundation

let V = 5
let INF = 999999

func minKey(_ key: [Int], _ mstSet: [Bool]) -> Int {
    var min = INF
    var minIndex = -1
    
    for v in 0..<V {
        if !mstSet[v] && key[v] < min {
            min = key[v]
            minIndex = v
        }
    }
    return minIndex
}

func printMST(_ parent: [Int], _ graph: [[Int]]) {
    print("Prim's MST Edges:")
    var totalWeight = 0
    for i in 1..<V {
        print("  \(parent[i]) - \(i) == \(graph[i][parent[i]])")
        totalWeight += graph[i][parent[i]]
    }
    print("Total Cost of MST: \(totalWeight)")
}

func runPrim(_ graph: [[Int]]) {
    var parent = Array(repeating: 0, count: V)
    var key = Array(repeating: INF, count: V)
    var mstSet = Array(repeating: false, count: V)
    
    key[0] = 0
    parent[0] = -1
    
    for _ in 0..<V - 1 {
        let u = minKey(key, mstSet)
        mstSet[u] = true
        
        for v in 0..<V {
            if graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v] {
                parent[v] = u
                key[v] = graph[u][v]
            }
        }
    }
    
    printMST(parent, graph)
}

func main() {
    let graph = [
        [0, 2, 0, 6, 0],
        [2, 0, 3, 8, 5],
        [0, 3, 0, 0, 7],
        [6, 8, 0, 0, 9],
        [0, 5, 7, 9, 0]
    ]
    
    print("=== Prim's Minimum Spanning Tree ===\n")
    runPrim(graph)
    
    print("\nPress Enter to exit...")
    _ = readLine()
}

main()
