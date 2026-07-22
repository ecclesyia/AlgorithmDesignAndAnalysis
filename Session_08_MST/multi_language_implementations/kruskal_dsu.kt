class Edge(var src: Int = 0, var dest: Int = 0, var weight: Int = 0)

class Graph(val V: Int, val E: Int) {
    val edges = Array(E) { Edge() }
}

class Subset(var parent: Int = 0, var rank: Int = 0)

fun find(subsets: Array<Subset>, i: Int): Int {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent)
    }
    return subsets[i].parent
}

fun union(subsets: Array<Subset>, x: Int, y: Int) {
    val xroot = find(subsets, x)
    val yroot = find(subsets, y)

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot
    } else {
        subsets[yroot].parent = xroot
        subsets[xroot].rank++
    }
}

fun runKruskal(graph: Graph) {
    val V = graph.V
    val result = Array(V - 1) { Edge() }
    var e = 0
    var i = 0

    // Sort edges
    graph.edges.sortBy { it.weight }

    val subsets = Array(V) { Subset(it, 0) }

    println("Kruskal's Edge Evaluation:")

    while (e < V - 1 && i < graph.E) {
        val nextEdge = graph.edges[i++]

        val x = find(subsets, nextEdge.src)
        val y = find(subsets, nextEdge.dest)

        if (x != y) {
            result[e++] = nextEdge
            union(subsets, x, y)
            println("  Accepted edge: ${nextEdge.src} - ${nextEdge.dest} (weight: ${nextEdge.weight})")
        } else {
            println("  Rejected edge: ${nextEdge.src} - ${nextEdge.dest} (weight: ${nextEdge.weight}) -> forms a cycle")
        }
    }

    println("\nFinal Minimum Spanning Tree Edges:")
    var minimumCost = 0
    for (idx in 0 until e) {
        println("  ${result[idx].src} - ${result[idx].dest} == ${result[idx].weight}")
        minimumCost += result[idx].weight
    }
    println("Total Cost of MST: $minimumCost")
}

fun main() {
    val V = 4
    val E = 5
    val graph = Graph(V, E)

    graph.edges[0] = Edge(0, 1, 10)
    graph.edges[1] = Edge(0, 2, 6)
    graph.edges[2] = Edge(0, 3, 5)
    graph.edges[3] = Edge(1, 3, 15)
    graph.edges[4] = Edge(2, 3, 4)

    println("=== Kruskal's Minimum Spanning Tree ===\n")
    runKruskal(graph)

    println()
    print("Press Enter to exit...")
    readLine()
}
