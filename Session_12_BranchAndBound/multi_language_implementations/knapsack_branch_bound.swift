import Foundation

class Node {
    var level: Int
    var profit: Int
    var weight: Int
    var bound: Double
    
    init(level: Int = 0, profit: Int = 0, weight: Int = 0, bound: Double = 0.0) {
        self.level = level
        self.profit = profit
        self.weight = weight
        self.bound = bound
    }
}

struct Item {
    let id: Int
    let weight: Int
    let value: Int
}

func calculateBound(_ u: Node, _ n: Int, _ W: Int, _ items: [Item]) -> Double {
    if u.weight >= W {
        return 0.0
    }
    
    var profitBound = Double(u.profit)
    var j = u.level + 1
    var totalWeight = u.weight
    
    while j < n && totalWeight + items[j].weight <= W {
        totalWeight += items[j].weight
        profitBound += Double(items[j].value)
        j += 1
    }
    
    if j < n {
        profitBound += Double(W - totalWeight) * (Double(items[j].value) / Double(items[j].weight))
    }
    
    return profitBound
}

func solveKnapsackBB(_ W: Int, _ items: inout [Item], _ n: Int) -> Int {
    // Sort items by ratio descending
    items.sort {
        let r1 = Double($0.value) / Double($0.weight)
        let r2 = Double($1.value) / Double($1.weight)
        return r1 > r2
    }
    
    var q = [Node]()
    
    let u = Node(level: -1, profit: 0, weight: 0, bound: 0.0)
    u.bound = calculateBound(u, n, W, items)
    
    var maxProfit = 0
    q.append(u)
    
    print("Branch and Bound Search Steps:")
    
    while !q.isEmpty {
        let currU = q.removeFirst()
        
        let v = Node()
        if currU.level == -1 {
            v.level = 0
        } else if currU.level == n - 1 {
            continue
        } else {
            v.level = currU.level + 1
        }
        
        // --- BRANCH 1: Include next item ---
        v.weight = currU.weight + items[v.level].weight
        v.profit = currU.profit + items[v.level].value
        
        if v.weight <= W && v.profit > maxProfit {
            maxProfit = v.profit
            print("  Updated max profit to: \(maxProfit) (Level \(v.level), Weight \(v.weight))")
        }
        
        v.bound = calculateBound(v, n, W, items)
        
        if v.bound > Double(maxProfit) {
            q.append(v)
            print(String(format: "    Branch WITH item %d enqueued. Bound = %.2f", items[v.level].id, v.bound))
        } else {
            print(String(format: "    Branch WITH item %d pruned. Bound (%.2f) <= MaxProfit (%d)", items[v.level].id, v.bound, maxProfit))
        }
        
        // --- BRANCH 2: Exclude next item ---
        let vExclude = Node(level: v.level, profit: currU.profit, weight: currU.weight, bound: 0.0)
        vExclude.bound = calculateBound(vExclude, n, W, items)
        
        if vExclude.bound > Double(maxProfit) {
            q.append(vExclude)
            print(String(format: "    Branch WITHOUT item %d enqueued. Bound = %.2f", items[v.level].id, vExclude.bound))
        } else {
            print(String(format: "    Branch WITHOUT item %d pruned. Bound (%.2f) <= MaxProfit (%d)", items[v.level].id, vExclude.bound, maxProfit))
        }
    }
    
    return maxProfit
}

func main() {
    let W = 10
    var items = [
        Item(id: 1, weight: 2, value: 40),
        Item(id: 2, weight: 5, value: 30),
        Item(id: 3, weight: 10, value: 50),
        Item(id: 4, weight: 5, value: 10)
    ]
    let n = items.count
    
    print("=== Branch and Bound: 0/1 Knapsack ===")
    print("Capacity: \(W)\n")
    
    let maxProfit = solveKnapsackBB(W, &items, n)
    
    print("\nMaximum Profit: \(maxProfit)")
    
    print("\nPress Enter to exit...")
    _ = readLine()
}

main()
