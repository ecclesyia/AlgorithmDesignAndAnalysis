import Foundation

let V = 9
let INF = 999999

func minDistance(_ dist: [Int], _ sptSet: [Bool]) -> Int {
    var min = INF
    var minIndex = -1
    
    for v in 0..<V {
        if !sptSet[v] && dist[v] <= min {
            min = dist[v]
            minIndex = v
        }
    }
    return minIndex
}

func printSolution(_ dist: [Int]) {
    print("Vertex \t Distance from Source")
    for i in 0..<V {
        if dist[i] == INF {
            print("\(i) \t INF")
        } else {
            print("\(i) \t \(dist[i])")
        }
    }
}

func runDijkstra(_ graph: [[Int]], _ src: Int) {
    var dist = Array(repeating: INF, count: V)
    var sptSet = Array(repeating: false, count: V)
    
    dist[src] = 0
    
    for _ in 0..<V - 1 {
        let u = minDistance(dist, sptSet)
        sptSet[u] = true
        
        for v in 0..<V {
            if !sptSet[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v] {
                dist[v] = dist[u] + graph[u][v]
            }
        }
    }
    
    printSolution(dist)
}

func main() {
    let graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ]
    
    print("=== Dijkstra's Single-Source Shortest Path ===")
    print("Starting from Source Vertex: 0\n")
    runDijkstra(graph, 0)
    
    print("\nPress Enter to exit...")
    _ = readLine()
}

main()
