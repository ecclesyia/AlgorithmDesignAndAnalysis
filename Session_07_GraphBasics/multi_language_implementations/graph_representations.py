# Session 07: Graph Representations in Python
# Shows how to represent a graph using:
# 1. Adjacency Matrix
# 2. Adjacency List

V = 4  # Number of vertices

# 1. Adjacency Matrix Representation
def create_adjacency_matrix():
    adj_matrix = [[0] * V for _ in range(V)]
    
    # Add edges
    adj_matrix[0][1] = 1
    adj_matrix[0][2] = 1
    adj_matrix[1][3] = 1
    adj_matrix[3][0] = 1
    return adj_matrix

def print_adjacency_matrix(adj_matrix):
    print("Adjacency Matrix:")
    for i in range(V):
        for j in range(V):
            print(f"{adj_matrix[i][j]} ", end="")
        print()
    print()

# 2. Adjacency List Representation
class AdjListNode:
    def __init__(self, dest):
        self.dest = dest
        self.next = None

class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.head_array = [None] * num_vertices

    # Add edge to graph (Directed)
    def add_edge(self, src, dest):
        new_node = AdjListNode(dest)
        
        # Insert at head of the list for src
        new_node.next = self.head_array[src]
        self.head_array[src] = new_node

def print_graph_list(graph):
    print("Adjacency List:")
    for v in range(graph.num_vertices):
        curr = graph.head_array[v]
        print(f"  Vertex {v}: ", end="")
        while curr:
            print(f"-> {curr.dest} ", end="")
            curr = curr.next
        print("-> NULL")
    print()

def main():
    # Adjacency Matrix
    adj_matrix = create_adjacency_matrix()
    print_adjacency_matrix(adj_matrix)

    # Adjacency List
    graph = Graph(V)
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 3)
    graph.add_edge(3, 0)
    print_graph_list(graph)

if __name__ == "__main__":
    main()
