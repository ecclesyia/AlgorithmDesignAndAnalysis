import Foundation

struct Edge {
    var src: Int
    var dest: Int
    var weight: Int
}

class Graph {
    var V: Int
    var E: Int
    var edges: [Edge]
    
    init(V: Int, E: Int) {
        self.V = V
        self.E = E
        self.edges = []
    }
}

struct Subset {
    var parent: Int
    var rank: Int
}

func find(_ subsets: inout [Subset], _ i: Int) -> Int {
    if subsets[i].parent != i {
        subsets[i].parent = find(&subsets, subsets[i].parent)
    }
    return subsets[i].parent
}

func union(_ subsets: inout [Subset], _ x: Int, _ y: Int) {
    let xroot = find(&subsets, x)
    let yroot = find(&subsets, y)
    
    if subsets[xroot].rank < subsets[yroot].rank {
        subsets[xroot].parent = yroot
    } else if subsets[xroot].rank > subsets[yroot].rank {
        subsets[yroot].parent = xroot
    } else {
        subsets[yroot].parent = xroot
        subsets[xroot].rank += 1
    }
}

func runKruskal(_ graph: inout Graph) {
    let V = graph.V
    var result = [Edge]()
    var e = 0
    var i = 0
    
    graph.edges.sort { $0.weight < $1.weight }
    
    var subsets = (0..<V).map { Subset(parent: $0, rank: 0) }
    
    print("Kruskal's Edge Evaluation:")
    
    while e < V - 1 && i < graph.E {
        let nextEdge = graph.edges[i]
        i += 1
        
        let x = find(&subsets, nextEdge.src)
        let y = find(&subsets, nextEdge.dest)
        
        if x != y {
            result.append(nextEdge)
            e += 1
            union(&subsets, x, y)
            print("  Accepted edge: \(nextEdge.src) - \(nextEdge.dest) (weight: \(nextEdge.weight))")
        } else {
            print("  Rejected edge: \(nextEdge.src) - \(nextEdge.dest) (weight: \(nextEdge.weight)) -> forms a cycle")
        }
    }
    
    print("\nFinal Minimum Spanning Tree Edges:")
    var minimumCost = 0
    for idx in 0..<e {
        print("  \(result[idx].src) - \(result[idx].dest) == \(result[idx].weight)")
        minimumCost += result[idx].weight
    }
    print("Total Cost of MST: \(minimumCost)")
}

func main() {
    let V = 4
    let E = 5
    var graph = Graph(V: V, E: E)
    
    graph.edges.append(Edge(src: 0, dest: 1, weight: 10))
    graph.edges.append(Edge(src: 0, dest: 2, weight: 6))
    graph.edges.append(Edge(src: 0, dest: 3, weight: 5))
    graph.edges.append(Edge(src: 1, dest: 3, weight: 15))
    graph.edges.append(Edge(src: 2, dest: 3, weight: 4))
    
    print("=== Kruskal's Minimum Spanning Tree ===\n")
    runKruskal(&graph)
    
    print("\nPress Enter to exit...")
    _ = readLine()
}

main()
