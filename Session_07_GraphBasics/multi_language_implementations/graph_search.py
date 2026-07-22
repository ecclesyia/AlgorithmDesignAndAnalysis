# Session 07: BFS and DFS Traversals in Python
# Uses an Adjacency List graph representation to demonstrate:
# 1. Breadth-First Search (Queue-based)
# 2. Depth-First Search (Recursive)

class Node:
    def __init__(self, dest):
        self.dest = dest
        self.next = None

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.head_array = [None] * vertices

    # Add undirected edge
    def add_edge(self, src, dest):
        node1 = Node(dest)
        node1.next = self.head_array[src]
        self.head_array[src] = node1

        node2 = Node(src)
        node2.next = self.head_array[dest]
        self.head_array[dest] = node2

# 1. Breadth-First Search (BFS)
def run_bfs(graph, start_vertex):
    visited = [False] * graph.V
    queue = []
    
    visited[start_vertex] = True
    queue.append(start_vertex)
    
    print("BFS: ", end="")
    
    while queue:
        curr = queue.pop(0)
        print(f"{curr} ", end="")
        
        temp = graph.head_array[curr]
        while temp:
            adj = temp.dest
            if not visited[adj]:
                visited[adj] = True
                queue.append(adj)
            temp = temp.next
    print()

# Helper recursive function for DFS
def dfs_helper(graph, vertex, visited):
    visited[vertex] = True
    print(f"{vertex} ", end="")
    
    temp = graph.head_array[vertex]
    while temp:
        adj = temp.dest
        if not visited[adj]:
            dfs_helper(graph, adj, visited)
        temp = temp.next

# 2. Depth-First Search (DFS)
def run_dfs(graph, start_vertex):
    visited = [False] * graph.V
    print("DFS: ", end="")
    dfs_helper(graph, start_vertex, visited)
    print()

def main():
    graph = Graph(5)
    
    # Setup a sample graph:
    # 0 --- 1 --- 3
    # |   /
    # |  /
    # 2 --- 4
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 2)
    graph.add_edge(1, 3)
    graph.add_edge(2, 4)

    run_bfs(graph, 0)
    run_dfs(graph, 0)

if __name__ == "__main__":
    main()
