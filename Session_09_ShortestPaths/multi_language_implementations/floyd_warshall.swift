import Foundation

let V = 4
let INF = 999999

func printMatrix(_ dist: [[Int]]) {
    print("Shortest distances between every pair of vertices:")
    for i in 0..<V {
        for j in 0..<V {
            if dist[i][j] == INF {
                print(String(format: "%7@", "INF"), terminator: "")
            } else {
                print(String(format: "%7d", dist[i][j]), terminator: "")
            }
        }
        print()
    }
}

func runFloydWarshall(_ graph: [[Int]]) {
    var dist = Array(repeating: Array(repeating: 0, count: V), count: V)
    
    for i in 0..<V {
        for j in 0..<V {
            dist[i][j] = graph[i][j]
        }
    }
    
    for k in 0..<V {
        for i in 0..<V {
            for j in 0..<V {
                if dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j] {
                    dist[i][j] = dist[i][k] + dist[k][j]
                }
            }
        }
    }
    
    printMatrix(dist)
}

func main() {
    let graph = [
        [0, 5, INF, 10],
        [INF, 0, 3, INF],
        [INF, INF, 0, 1],
        [INF, INF, INF, 0]
    ]
    
    print("=== Floyd-Warshall All-Pairs Shortest Path ===\n")
    runFloydWarshall(graph)
    
    print("\nPress Enter to exit...")
    _ = readLine()
}

main()
