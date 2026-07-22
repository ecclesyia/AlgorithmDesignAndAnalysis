import java.util.Locale

const val V = 4
const val INF = 999999

fun printMatrix(dist: Array<IntArray>) {
    println("Shortest distances between every pair of vertices:")
    for (i in 0 until V) {
        for (j in 0 until V) {
            if (dist[i][j] == INF) {
                print(String.format(Locale.US, "%7s", "INF"))
            } else {
                print(String.format(Locale.US, "%7d", dist[i][j]))
            }
        }
        println()
    }
}

fun runFloydWarshall(graph: Array<IntArray>) {
    val dist = Array(V) { IntArray(V) }

    for (i in 0 until V) {
        for (j in 0 until V) {
            dist[i][j] = graph[i][j]
        }
    }

    for (k in 0 until V) {
        for (i in 0 until V) {
            for (j in 0 until V) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]
                }
            }
        }
    }

    printMatrix(dist)
}

fun main() {
    val graph = arrayOf(
        intArrayOf(0, 5, INF, 10),
        intArrayOf(INF, 0, 3, INF),
        intArrayOf(INF, INF, 0, 1),
        intArrayOf(INF, INF, INF, 0)
    )

    println("=== Floyd-Warshall All-Pairs Shortest Path ===\n")
    runFloydWarshall(graph)

    println()
    print("Press Enter to exit...")
    readLine()
}
