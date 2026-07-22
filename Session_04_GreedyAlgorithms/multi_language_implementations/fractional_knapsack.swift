import Foundation

struct Item {
    let id: Int
    let value: Double
    let weight: Double
    var ratio: Double = 0.0
}

func solveFractionalKnapsack(_ items: [Item], _ capacity: Double) {
    var itemsWithRatio = items
    for i in 0..<itemsWithRatio.count {
        itemsWithRatio[i].ratio = itemsWithRatio[i].value / itemsWithRatio[i].weight
    }

    let sortedItems = itemsWithRatio.sorted { $0.ratio > $1.ratio }
    var totalValue = 0.0
    var remainingCapacity = capacity

    for item in sortedItems {
        if remainingCapacity <= 0 {
            break
        }
        if item.weight <= remainingCapacity {
            remainingCapacity -= item.weight
            totalValue += item.value
        } else {
            let fraction = remainingCapacity / item.weight
            totalValue += item.value * fraction
            remainingCapacity = 0.0
        }
    }
    print(String(format: "Max Knapsack value: %.2f", totalValue))
}

func main() {
    let items = [
        Item(id: 1, value: 60.0, weight: 10.0, ratio: 0.0),
        Item(id: 2, value: 100.0, weight: 20.0, ratio: 0.0),
        Item(id: 3, value: 120.0, weight: 30.0, ratio: 0.0)
    ]
    solveFractionalKnapsack(items, 50.0)
    print("\nPress Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
