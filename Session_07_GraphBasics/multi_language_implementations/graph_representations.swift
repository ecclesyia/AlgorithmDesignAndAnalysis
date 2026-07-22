import Foundation

let V = 4

func createAdjacencyMatrix(_ adjMatrix: inout [[Int]]) {
    for i in 0..<V {
        for j in 0..<V {
            adjMatrix[i][j] = 0
        }
    }
    adjMatrix[0][1] = 1
    adjMatrix[0][2] = 1
    adjMatrix[1][3] = 1
    adjMatrix[3][0] = 1
}

func printAdjacencyMatrix(_ adjMatrix: [[Int]]) {
    print("Adjacency Matrix:")
    for i in 0..<V {
        for j in 0..<V {
            print("\(adjMatrix[i][j]) ", terminator: "")
        }
        print()
    }
    print()
}

class AdjListNode {
    var dest: Int
    var next: AdjListNode?
    
    init(dest: Int, next: AdjListNode? = nil) {
        self.dest = dest
        self.next = next
    }
}

class AdjList {
    var head: AdjListNode?
}

class Graph {
    var numVertices: Int
    var array: [AdjList]
    
    init(numVertices: Int) {
        self.numVertices = numVertices
        self.array = (0..<numVertices).map { _ in AdjList() }
    }
}

func addEdge(_ graph: Graph, _ src: Int, _ dest: Int) {
    let newNode = AdjListNode(dest: dest)
    newNode.next = graph.array[src].head
    graph.array[src].head = newNode
}

func printGraphList(_ graph: Graph) {
    print("Adjacency List:")
    for v in 0..<graph.numVertices {
        var curr = graph.array[v].head
        print("  Vertex \(v): ", terminator: "")
        while let node = curr {
            print("-> \(node.dest) ", terminator: "")
            curr = node.next
        }
        print("-> NULL")
    }
    print()
}

func main() {
    print("=== Graph Representations in Swift ===\n")
    
    var adjMatrix = Array(repeating: Array(repeating: 0, count: V), count: V)
    createAdjacencyMatrix(&adjMatrix)
    printAdjacencyMatrix(adjMatrix)
    
    let graph = Graph(numVertices: V)
    addEdge(graph, 0, 1)
    addEdge(graph, 0, 2)
    addEdge(graph, 1, 3)
    addEdge(graph, 3, 0)
    printGraphList(graph)
    
    print("Press Enter to exit...")
    _ = readLine()
}

main()
