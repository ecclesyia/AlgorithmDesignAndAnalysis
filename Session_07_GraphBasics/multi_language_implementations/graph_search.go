package main

import (
	"bufio"
	"fmt"
	"os"
)

type Node struct {
	dest int
	next *Node
}

type List struct {
	head *Node
}

type Graph struct {
	V     int
	array []List
}

func createGraph(vertices int) *Graph {
	g := &Graph{
		V:     vertices,
		array: make([]List, vertices),
	}
	return g
}

func addEdge(graph *Graph, src, dest int) {
	node1 := &Node{dest: dest, next: graph.array[src].head}
	graph.array[src].head = node1

	node2 := &Node{dest: src, next: graph.array[dest].head}
	graph.array[dest].head = node2
}

func runBFS(graph *Graph, startVertex int) {
	visited := make([]bool, graph.V)
	queue := make([]int, graph.V)
	front, rear := 0, 0

	visited[startVertex] = true
	queue[rear] = startVertex
	rear++

	fmt.Printf("BFS Starting from Vertex %d: ", startVertex)

	for front < rear {
		curr := queue[front]
		front++
		fmt.Printf("%d ", curr)

		temp := graph.array[curr].head
		for temp != nil {
			adj := temp.dest
			if !visited[adj] {
				visited[adj] = true
				queue[rear] = adj
				rear++
			}
			temp = temp.next
		}
	}
	fmt.Println()
}

func dfsHelper(graph *Graph, vertex int, visited []bool) {
	visited[vertex] = true
	fmt.Printf("%d ", vertex)

	temp := graph.array[vertex].head
	for temp != nil {
		adj := temp.dest
		if !visited[adj] {
			dfsHelper(graph, adj, visited)
		}
		temp = temp.next
	}
}

func runDFS(graph *Graph, startVertex int) {
	visited := make([]bool, graph.V)
	fmt.Printf("DFS Starting from Vertex %d: ", startVertex)
	dfsHelper(graph, startVertex, visited)
	fmt.Println()
}

func main() {
	numVertices := 5
	graph := createGraph(numVertices)

	addEdge(graph, 0, 1)
	addEdge(graph, 0, 2)
	addEdge(graph, 1, 2)
	addEdge(graph, 1, 3)
	addEdge(graph, 2, 4)

	fmt.Println("=== Graph Search Algorithms ===")
	fmt.Println()
	runBFS(graph, 0)
	runDFS(graph, 0)

	fmt.Println()
	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
