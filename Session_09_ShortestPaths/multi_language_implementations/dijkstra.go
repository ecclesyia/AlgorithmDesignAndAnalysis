package main

import (
	"bufio"
	"fmt"
	"os"
)

const V = 9
const INF = 999999

func minDistance(dist []int, sptSet []bool) int {
	min := INF
	min_index := -1

	for v := 0; v < V; v++ {
		if !sptSet[v] && dist[v] <= min {
			min = dist[v]
			min_index = v
		}
	}
	return min_index
}

func printSolution(dist []int) {
	fmt.Println("Vertex \t Distance from Source")
	for i := 0; i < V; i++ {
		if dist[i] == INF {
			fmt.Printf("%d \t INF\n", i)
		} else {
			fmt.Printf("%d \t %d\n", i, dist[i])
		}
	}
}

func runDijkstra(graph [V][V]int, src int) {
	var dist [V]int
	var sptSet [V]bool

	for i := 0; i < V; i++ {
		dist[i] = INF
		sptSet[i] = false
	}

	dist[src] = 0

	for count := 0; count < V-1; count++ {
		u := minDistance(dist[:], sptSet[:])
		sptSet[u] = true

		for v := 0; v < V; v++ {
			if !sptSet[v] && graph[u][v] != 0 && dist[u] != INF && dist[u]+graph[u][v] < dist[v] {
				dist[v] = dist[u] + graph[u][v]
			}
		}
	}

	printSolution(dist[:])
}

func main() {
	graph := [V][V]int{
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0},
	}

	fmt.Println("=== Dijkstra's Single-Source Shortest Path ===")
	fmt.Println("Starting from Source Vertex: 0")
	fmt.Println()
	runDijkstra(graph, 0)

	fmt.Println()
	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
