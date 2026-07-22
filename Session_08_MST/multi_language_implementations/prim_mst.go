package main

import (
	"bufio"
	"fmt"
	"os"
)

const V = 5
const INF = 999999

func minKey(key []int, mstSet []bool) int {
	min := INF
	min_index := -1

	for v := 0; v < V; v++ {
		if !mstSet[v] && key[v] < min {
			min = key[v]
			min_index = v
		}
	}
	return min_index
}

func printMST(parent []int, graph [V][V]int) {
	fmt.Println("Prim's MST Edges:")
	totalWeight := 0
	for i := 1; i < V; i++ {
		fmt.Printf("  %d - %d == %d\n", parent[i], i, graph[i][parent[i]])
		totalWeight += graph[i][parent[i]]
	}
	fmt.Printf("Total Cost of MST: %d\n", totalWeight)
}

func runPrim(graph [V][V]int) {
	var parent [V]int
	var key [V]int
	var mstSet [V]bool

	for i := 0; i < V; i++ {
		key[i] = INF
		mstSet[i] = false
	}

	key[0] = 0
	parent[0] = -1

	for count := 0; count < V-1; count++ {
		u := minKey(key[:], mstSet[:])
		mstSet[u] = true

		for v := 0; v < V; v++ {
			if graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v] {
				parent[v] = u
				key[v] = graph[u][v]
			}
		}
	}

	printMST(parent[:], graph)
}

func main() {
	graph := [V][V]int{
		{0, 2, 0, 6, 0},
		{2, 0, 3, 8, 5},
		{0, 3, 0, 0, 7},
		{6, 8, 0, 0, 9},
		{0, 5, 7, 9, 0},
	}

	fmt.Println("=== Prim's Minimum Spanning Tree ===")
	fmt.Println()
	runPrim(graph)

	fmt.Println()
	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
