import Foundation

class Node {
    var dest: Int
    var next: Node?
    
    init(dest: Int, next: Node? = nil) {
        self.dest = dest
        self.next = next
    }
}

class List {
    var head: Node?
}

class Graph {
    var V: Int
    var array: [List]
    
    init(V: Int) {
        self.V = V
        self.array = (0..<V).map { _ in List() }
    }
}

func createGraph(_ vertices: Int) -> Graph {
    return Graph(V: vertices)
}

func addEdge(_ graph: Graph, _ src: Int, _ dest: Int) {
    let node1 = Node(dest: dest, next: graph.array[src].head)
    graph.array[src].head = node1
    
    let node2 = Node(dest: src, next: graph.array[dest].head)
    graph.array[dest].head = node2
}

func runBFS(_ graph: Graph, _ startVertex: Int) {
    var visited = Array(repeating: false, count: graph.V)
    var queue = Array(repeating: 0, count: graph.V)
    var front = 0
    var rear = 0
    
    visited[startVertex] = true
    queue[rear] = startVertex
    rear += 1
    
    print("BFS Starting from Vertex \(startVertex): ", terminator: "")
    
    while front < rear {
        let curr = queue[front]
        front += 1
        print("\(curr) ", terminator: "")
        
        var temp = graph.array[curr].head
        while let node = temp {
            let adj = node.dest
            if !visited[adj] {
                visited[adj] = true
                queue[rear] = adj
                rear += 1
            }
            temp = node.next
        }
    }
    print()
}

func dfsHelper(_ graph: Graph, _ vertex: Int, _ visited: inout [Bool]) {
    visited[vertex] = true
    print("\(vertex) ", terminator: "")
    
    var temp = graph.array[vertex].head
    while let node = temp {
        let adj = node.dest
        if !visited[adj] {
            dfsHelper(graph, adj, &visited)
        }
        temp = node.next
    }
}

func runDFS(_ graph: Graph, _ startVertex: Int) {
    var visited = Array(repeating: false, count: graph.V)
    print("DFS Starting from Vertex \(startVertex): ", terminator: "")
    dfsHelper(graph, startVertex, &visited)
    print()
}

func main() {
    let numVertices = 5
    let graph = createGraph(numVertices)
    
    addEdge(graph, 0, 1)
    addEdge(graph, 0, 2)
    addEdge(graph, 1, 2)
    addEdge(graph, 1, 3)
    addEdge(graph, 2, 4)
    
    print("=== Graph Search Algorithms ===\n")
    runBFS(graph, 0)
    runDFS(graph, 0)
    
    print()
    print("Press Enter to exit...")
    _ = readLine()
}

main()
