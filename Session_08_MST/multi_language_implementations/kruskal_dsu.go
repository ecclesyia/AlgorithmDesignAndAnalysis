package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Edge struct {
	src, dest, weight int
}

type Graph struct {
	V, E  int
	edges []Edge
}

type Subset struct {
	parent, rank int
}

func createGraph(V, E int) *Graph {
	return &Graph{
		V:     V,
		E:     E,
		edges: make([]Edge, E),
	}
}

func find(subsets []Subset, i int) int {
	if subsets[i].parent != i {
		subsets[i].parent = find(subsets, subsets[i].parent)
	}
	return subsets[i].parent
}

func union(subsets []Subset, x, y int) {
	xroot := find(subsets, x)
	yroot := find(subsets, y)

	if subsets[xroot].rank < subsets[yroot].rank {
		subsets[xroot].parent = yroot
	} else if subsets[xroot].rank > subsets[yroot].rank {
		subsets[yroot].parent = xroot
	} else {
		subsets[yroot].parent = xroot
		subsets[xroot].rank++
	}
}

func runKruskal(graph *Graph) {
	V := graph.V
	result := make([]Edge, V-1)
	e := 0
	i := 0

	// Sort edges
	sort.Slice(graph.edges, func(a, b int) bool {
		return graph.edges[a].weight < graph.edges[b].weight
	})

	subsets := make([]Subset, V)
	for v := 0; v < V; v++ {
		subsets[v].parent = v
		subsets[v].rank = 0
	}

	fmt.Println("Kruskal's Edge Evaluation:")

	for e < V-1 && i < graph.E {
		nextEdge := graph.edges[i]
		i++

		x := find(subsets, nextEdge.src)
		y := find(subsets, nextEdge.dest)

		if x != y {
			result[e] = nextEdge
			e++
			union(subsets, x, y)
			fmt.Printf("  Accepted edge: %d - %d (weight: %d)\n", nextEdge.src, nextEdge.dest, nextEdge.weight)
		} else {
			fmt.Printf("  Rejected edge: %d - %d (weight: %d) -> forms a cycle\n", nextEdge.src, nextEdge.dest, nextEdge.weight)
		}
	}

	fmt.Println("\nFinal Minimum Spanning Tree Edges:")
	minimumCost := 0
	for idx := 0; idx < e; idx++ {
		fmt.Printf("  %d - %d == %d\n", result[idx].src, result[idx].dest, result[idx].weight)
		minimumCost += result[idx].weight
	}
	fmt.Printf("Total Cost of MST: %d\n", minimumCost)
}

func main() {
	V := 4
	E := 5
	graph := createGraph(V, E)

	graph.edges[0] = Edge{src: 0, dest: 1, weight: 10}
	graph.edges[1] = Edge{src: 0, dest: 2, weight: 6}
	graph.edges[2] = Edge{src: 0, dest: 3, weight: 5}
	graph.edges[3] = Edge{src: 1, dest: 3, weight: 15}
	graph.edges[4] = Edge{src: 2, dest: 3, weight: 4}

	fmt.Println("=== Kruskal's Minimum Spanning Tree ===")
	fmt.Println()
	runKruskal(graph)

	fmt.Println()
	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
