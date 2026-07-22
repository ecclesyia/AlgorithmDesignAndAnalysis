package main

import (
	"bufio"
	"fmt"
	"os"
)

const V = 4 // Number of vertices

// 1. Adjacency Matrix Representation
func createAdjacencyMatrix(adjMatrix *[V][V]int) {
	// Initialize matrix with 0s
	for i := 0; i < V; i++ {
		for j := 0; j < V; j++ {
			adjMatrix[i][j] = 0
		}
	}

	// Add edges
	adjMatrix[0][1] = 1
	adjMatrix[0][2] = 1
	adjMatrix[1][3] = 1
	adjMatrix[3][0] = 1
}

func printAdjacencyMatrix(adjMatrix *[V][V]int) {
	fmt.Println("Adjacency Matrix:")
	for i := 0; i < V; i++ {
		for j := 0; j < V; j++ {
			fmt.Printf("%d ", adjMatrix[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}

// 2. Adjacency List Representation
type AdjListNode struct {
	dest int
	next *AdjListNode
}

type AdjList struct {
	head *AdjListNode
}

type Graph struct {
	numVertices int
	array       []AdjList
}

// Create a graph of V vertices
func createGraph(numVertices int) *Graph {
	g := &Graph{
		numVertices: numVertices,
		array:       make([]AdjList, numVertices),
	}
	for i := 0; i < numVertices; i++ {
		g.array[i].head = nil
	}
	return g
}

// Add edge to graph (Directed)
func addEdge(graph *Graph, src, dest int) {
	newNode := &AdjListNode{dest: dest}
	// Insert at head of the list for src
	newNode.next = graph.array[src].head
	graph.array[src].head = newNode
}

func printGraphList(graph *Graph) {
	fmt.Println("Adjacency List:")
	for v := 0; v < graph.numVertices; v++ {
		curr := graph.array[v].head
		fmt.Printf("  Vertex %d: ", v)
		for curr != nil {
			fmt.Printf("-> %d ", curr.dest)
			curr = curr.next
		}
		fmt.Println("-> NULL")
	}
	fmt.Println()
}

func main() {
	fmt.Println("=== Graph Representations in Go ===")
	fmt.Println()

	// Adjacency Matrix
	var adjMatrix [V][V]int
	createAdjacencyMatrix(&adjMatrix)
	printAdjacencyMatrix(&adjMatrix)

	// Adjacency List
	graph := createGraph(V)
	addEdge(graph, 0, 1)
	addEdge(graph, 0, 2)
	addEdge(graph, 1, 3)
	addEdge(graph, 3, 0)
	printGraphList(graph)

	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
