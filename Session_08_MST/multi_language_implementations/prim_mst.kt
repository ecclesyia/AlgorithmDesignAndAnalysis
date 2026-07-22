const val V = 5
const val INF = 999999

fun minKey(key: IntArray, mstSet: BooleanArray): Int {
    var min = INF
    var minIndex = -1

    for (v in 0 until V) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v]
            minIndex = v
        }
    }
    return minIndex
}

fun printMST(parent: IntArray, graph: Array<IntArray>) {
    println("Prim's MST Edges:")
    var totalWeight = 0
    for (i in 1 until V) {
        println("  ${parent[i]} - $i == ${graph[i][parent[i]]}")
        totalWeight += graph[i][parent[i]]
    }
    println("Total Cost of MST: $totalWeight")
}

fun runPrim(graph: Array<IntArray>) {
    val parent = IntArray(V)
    val key = IntArray(V)
    val mstSet = BooleanArray(V)

    for (i in 0 until V) {
        key[i] = INF
        mstSet[i] = false
    }

    key[0] = 0
    parent[0] = -1

    for (count in 0 until V - 1) {
        val u = minKey(key, mstSet)
        mstSet[u] = true

        for (v in 0 until V) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u
                key[v] = graph[u][v]
            }
        }
    }

    printMST(parent, graph)
}

fun main() {
    val graph = arrayOf(
        intArrayOf(0, 2, 0, 6, 0),
        intArrayOf(2, 0, 3, 8, 5),
        intArrayOf(0, 3, 0, 0, 7),
        intArrayOf(6, 8, 0, 0, 9),
        intArrayOf(0, 5, 7, 9, 0)
    )

    println("=== Prim's Minimum Spanning Tree ===\n")
    runPrim(graph)

    println()
    print("Press Enter to exit...")
    readLine()
}
