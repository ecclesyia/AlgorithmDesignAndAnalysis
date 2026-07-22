const val V = 9
const val INF = 999999

fun minDistance(dist: IntArray, sptSet: BooleanArray): Int {
    var min = INF
    var minIndex = -1

    for (v in 0 until V) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v]
            minIndex = v
        }
    }
    return minIndex
}

fun printSolution(dist: IntArray) {
    println("Vertex \t Distance from Source")
    for (i in 0 until V) {
        if (dist[i] == INF) {
            println("$i \t INF")
        } else {
            println("$i \t ${dist[i]}")
        }
    }
}

fun runDijkstra(graph: Array<IntArray>, src: Int) {
    val dist = IntArray(V)
    val sptSet = BooleanArray(V)

    for (i in 0 until V) {
        dist[i] = INF
        sptSet[i] = false
    }

    dist[src] = 0

    for (count in 0 until V - 1) {
        val u = minDistance(dist, sptSet)
        sptSet[u] = true

        for (v in 0 until V) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v]
            }
        }
    }

    printSolution(dist)
}

fun main() {
    val graph = arrayOf(
        intArrayOf(0, 4, 0, 0, 0, 0, 0, 8, 0),
        intArrayOf(4, 0, 8, 0, 0, 0, 0, 11, 0),
        intArrayOf(0, 8, 0, 7, 0, 4, 0, 0, 2),
        intArrayOf(0, 0, 7, 0, 9, 14, 0, 0, 0),
        intArrayOf(0, 0, 0, 9, 0, 10, 0, 0, 0),
        intArrayOf(0, 0, 4, 14, 10, 0, 2, 0, 0),
        intArrayOf(0, 0, 0, 0, 0, 2, 0, 1, 6),
        intArrayOf(8, 11, 0, 0, 0, 0, 1, 0, 7),
        intArrayOf(0, 0, 2, 0, 0, 0, 6, 7, 0)
    )

    println("=== Dijkstra's Single-Source Shortest Path ===")
    println("Starting from Source Vertex: 0\n")
    runDijkstra(graph, 0)

    println()
    print("Press Enter to exit...")
    readLine()
}
