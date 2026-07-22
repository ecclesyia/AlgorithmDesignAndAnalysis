package main

import (
	"bufio"
	"fmt"
	"os"
)

const V = 4
const INF = 999999

func printMatrix(dist [V][V]int) {
	fmt.Println("Shortest distances between every pair of vertices:")
	for i := 0; i < V; i++ {
		for j := 0; j < V; j++ {
			if dist[i][j] == INF {
				fmt.Printf("%7s", "INF")
			} else {
				fmt.Printf("%7d", dist[i][j])
			}
		}
		fmt.Println()
	}
}

func runFloydWarshall(graph [V][V]int) {
	var dist [V][V]int

	for i := 0; i < V; i++ {
		for j := 0; j < V; j++ {
			dist[i][j] = graph[i][j]
		}
	}

	for k := 0; k < V; k++ {
		for i := 0; i < V; i++ {
			for j := 0; j < V; j++ {
				if dist[i][k] != INF && dist[k][j] != INF && dist[i][k]+dist[k][j] < dist[i][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	printMatrix(dist)
}

func main() {
	graph := [V][V]int{
		{0, 5, INF, 10},
		{INF, 0, 3, INF},
		{INF, INF, 0, 1},
		{INF, INF, INF, 0},
	}

	fmt.Println("=== Floyd-Warshall All-Pairs Shortest Path ===")
	fmt.Println()
	runFloydWarshall(graph)

	fmt.Println()
	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
