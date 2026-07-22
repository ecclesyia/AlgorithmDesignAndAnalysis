import java.util.LinkedList
import java.util.Queue
import java.util.Locale

class Node(
    var level: Int = 0,
    var profit: Int = 0,
    var weight: Int = 0,
    var bound: Double = 0.0
)

class Item(
    val id: Int,
    val weight: Int,
    val value: Int
)

fun calculateBound(u: Node, n: Int, W: Int, items: Array<Item>): Double {
    if (u.weight >= W) return 0.0

    var profitBound = u.profit.toDouble()
    var j = u.level + 1
    var totalWeight = u.weight

    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight
        profitBound += items[j].value
        j++
    }

    if (j < n) {
        profitBound += (W - totalWeight) * (items[j].value.toDouble() / items[j].weight)
    }

    return profitBound
}

fun solveKnapsackBB(W: Int, items: Array<Item>, n: Int): Int {
    // Sort items by ratio descending
    items.sortWith { a, b ->
        val r1 = a.value.toDouble() / a.weight
        val r2 = b.value.toDouble() / b.weight
        r2.compareTo(r1)
    }

    val q: Queue<Node> = LinkedList()

    val u = Node(-1, 0, 0, 0.0)
    u.bound = calculateBound(u, n, W, items)

    var maxProfit = 0
    q.add(u)

    println("Branch and Bound Search Steps:")

    while (!q.isEmpty()) {
        val currU = q.poll()

        val v = Node()
        if (currU.level == -1) {
            v.level = 0
        } else if (currU.level == n - 1) {
            continue
        } else {
            v.level = currU.level + 1
        }

        // --- BRANCH 1: Include next item ---
        v.weight = currU.weight + items[v.level].weight
        v.profit = currU.profit + items[v.level].value

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit
            println("  Updated max profit to: $maxProfit (Level ${v.level}, Weight ${v.weight})")
        }

        v.bound = calculateBound(v, n, W, items)

        if (v.bound > maxProfit) {
            q.add(v)
            println(String.format(Locale.US, "    Branch WITH item %d enqueued. Bound = %.2f", items[v.level].id, v.bound))
        } else {
            println(String.format(Locale.US, "    Branch WITH item %d pruned. Bound (%.2f) <= MaxProfit (%d)", items[v.level].id, v.bound, maxProfit))
        }

        // --- BRANCH 2: Exclude next item ---
        val vExclude = Node(v.level, currU.profit, currU.weight, 0.0)
        vExclude.bound = calculateBound(vExclude, n, W, items)

        if (vExclude.bound > maxProfit) {
            q.add(vExclude)
            println(String.format(Locale.US, "    Branch WITHOUT item %d enqueued. Bound = %.2f", items[v.level].id, vExclude.bound))
        } else {
            println(String.format(Locale.US, "    Branch WITHOUT item %d pruned. Bound (%.2f) <= MaxProfit (%d)", items[v.level].id, vExclude.bound, maxProfit))
        }
    }

    return maxProfit
}

fun main() {
    val W = 10
    val items = arrayOf(
        Item(1, 2, 40),
        Item(2, 5, 30),
        Item(3, 10, 50),
        Item(4, 5, 10)
    )
    val n = items.size

    println("=== Branch and Bound: 0/1 Knapsack ===")
    println("Capacity: $W\n")

    val maxProfit = solveKnapsackBB(W, items, n)

    println("\nMaximum Profit: $maxProfit")

    println()
    print("Press Enter to exit...")
    readLine()
}
