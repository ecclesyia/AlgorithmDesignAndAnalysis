import java.util.Scanner

class AdjListNode(val dest: Int, var next: AdjListNode? = null)

class AdjList(var head: AdjListNode? = null)

class Graph(val numVertices: Int) {
    val array = Array(numVertices) { AdjList() }
}

fun createAdjacencyMatrix(adjMatrix: Array<IntArray>) {
    for (i in adjMatrix.indices) {
        for (j in adjMatrix[i].indices) {
            adjMatrix[i][j] = 0
        }
    }
    adjMatrix[0][1] = 1
    adjMatrix[0][2] = 1
    adjMatrix[1][3] = 1
    adjMatrix[3][0] = 1
}

fun printAdjacencyMatrix(adjMatrix: Array<IntArray>) {
    println("Adjacency Matrix:")
    for (row in adjMatrix) {
        for (cell in row) {
            print("$cell ")
        }
        println()
    }
    println()
}

fun addEdge(graph: Graph, src: Int, dest: Int) {
    val newNode = AdjListNode(dest)
    newNode.next = graph.array[src].head
    graph.array[src].head = newNode
}

fun printGraphList(graph: Graph) {
    println("Adjacency List:")
    for (v in 0 until graph.numVertices) {
        var curr = graph.array[v].head
        print("  Vertex $v: ")
        while (curr != null) {
            print("-> ${curr.dest} ")
            curr = curr.next
        }
        println("-> NULL")
    }
    println()
}

fun main() {
    println("=== Graph Representations in Kotlin ===\n")
    val v = 4
    val adjMatrix = Array(v) { IntArray(v) }
    createAdjacencyMatrix(adjMatrix)
    printAdjacencyMatrix(adjMatrix)

    val graph = Graph(v)
    addEdge(graph, 0, 1)
    addEdge(graph, 0, 2)
    addEdge(graph, 1, 3)
    addEdge(graph, 3, 0)
    printGraphList(graph)

    print("Press Enter to exit...")
    readLine()
}
