import java.util.Scanner

data class Item(val id: Int, val value: Double, val weight: Double, var ratio: Double = 0.0)

fun solveFractionalKnapsack(items: List<Item>, capacity: Double) {
    for (item in items) {
        item.ratio = item.value / item.weight
    }
    
    val sortedItems = items.sortedByDescending { it.ratio }
    var totalValue = 0.0
    var remainingCapacity = capacity

    for (item in sortedItems) {
        if (remainingCapacity <= 0) break
        if (item.weight <= remainingCapacity) {
            remainingCapacity -= item.weight
            totalValue += item.value
        } else {
            val fraction = remainingCapacity / item.weight
            totalValue += item.value * fraction
            remainingCapacity = 0.0
        }
    }
    System.out.format("Max Knapsack value: %.2f\n", totalValue)
}

fun main() {
    val items = listOf(
        Item(1, 60.0, 10.0),
        Item(2, 100.0, 20.0),
        Item(3, 120.0, 30.0)
    )
    solveFractionalKnapsack(items, 50.0)
    println()
    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
