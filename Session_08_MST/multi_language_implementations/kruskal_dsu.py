# Session 08: Kruskal's Algorithm with Disjoint Set Union in Python

class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

class Graph:
    def __init__(self, V, E):
        self.V = V
        self.E = E
        self.edges = []

class Subset:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank

def find(subsets, i):
    if subsets[i].parent != i:
        subsets[i].parent = find(subsets, subsets[i].parent)
    return subsets[i].parent

def union(subsets, x, y):
    xr = find(subsets, x)
    yr = find(subsets, y)
    if subsets[xr].rank < subsets[yr].rank:
        subsets[xr].parent = yr
    elif subsets[xr].rank > subsets[yr].rank:
        subsets[yr].parent = xr
    else:
        subsets[yr].parent = xr
        subsets[xr].rank += 1

def run_kruskal(graph):
    V = graph.V
    result = []
    e = 0
    i = 0
    
    # Sort edges by weight
    graph.edges.sort(key=lambda edge: edge.weight)
    
    subsets = [Subset(v, 0) for v in range(V)]
    
    while e < V - 1 and i < graph.E:
        next_edge = graph.edges[i]
        i += 1
        x = find(subsets, next_edge.src)
        y = find(subsets, next_edge.dest)
        
        if x != y:
            result.append(next_edge)
            e += 1
            union(subsets, x, y)
            
    print("Kruskal MST Edges:")
    cost = 0
    for edge in result:
        print(f"  {edge.src} - {edge.dest} == {edge.weight}")
        cost += edge.weight
    print(f"Total Cost: {cost}")

def main():
    graph = Graph(4, 5)
    graph.edges.append(Edge(0, 1, 10))
    graph.edges.append(Edge(0, 2, 6))
    graph.edges.append(Edge(0, 3, 5))
    graph.edges.append(Edge(1, 3, 15))
    graph.edges.append(Edge(2, 3, 4))
    
    run_kruskal(graph)

if __name__ == "__main__":
    main()
