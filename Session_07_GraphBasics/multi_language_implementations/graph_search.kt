class Node(val dest: Int, var next: Node? = null)

class List(var head: Node? = null)

class Graph(val V: Int) {
    val array = Array(V) { List() }
}

fun createGraph(vertices: Int): Graph {
    return Graph(vertices)
}

fun addEdge(graph: Graph, src: Int, dest: Int) {
    val node1 = Node(dest, graph.array[src].head)
    graph.array[src].head = node1

    val node2 = Node(src, graph.array[dest].head)
    graph.array[dest].head = node2
}

fun runBFS(graph: Graph, startVertex: Int) {
    val visited = BooleanArray(graph.V)
    val queue = IntArray(graph.V)
    var front = 0
    var rear = 0

    visited[startVertex] = true
    queue[rear++] = startVertex

    print("BFS Starting from Vertex $startVertex: ")

    while (front < rear) {
        val curr = queue[front++]
        print("$curr ")

        var temp = graph.array[curr].head
        while (temp != null) {
            val adj = temp.dest
            if (!visited[adj]) {
                visited[adj] = true
                queue[rear++] = adj
            }
            temp = temp.next
        }
    }
    println()
}

fun dfsHelper(graph: Graph, vertex: Int, visited: BooleanArray) {
    visited[vertex] = true
    print("$vertex ")

    var temp = graph.array[vertex].head
    while (temp != null) {
        val adj = temp.dest
        if (!visited[adj]) {
            dfsHelper(graph, adj, visited)
        }
        temp = temp.next
    }
}

fun runDFS(graph: Graph, startVertex: Int) {
    val visited = BooleanArray(graph.V)
    print("DFS Starting from Vertex $startVertex: ")
    dfsHelper(graph, startVertex, visited)
    println()
}

fun main() {
    val numVertices = 5
    val graph = createGraph(numVertices)

    addEdge(graph, 0, 1)
    addEdge(graph, 0, 2)
    addEdge(graph, 1, 2)
    addEdge(graph, 1, 3)
    addEdge(graph, 2, 4)

    println("=== Graph Search Algorithms ===\n")
    runBFS(graph, 0)
    runDFS(graph, 0)

    println()
    print("Press Enter to exit...")
    readLine()
}
