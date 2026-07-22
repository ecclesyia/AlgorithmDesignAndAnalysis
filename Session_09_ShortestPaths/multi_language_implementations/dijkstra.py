# Session 09: Dijkstra's Single Source Shortest Path in Python

V = 9
INF = 999999

def min_distance(dist, spt_set):
    min_val = INF
    min_index = -1
    for v in range(V):
        if not spt_set[v] and dist[v] <= min_val:
            min_val = dist[v]
            min_index = v
    return min_index

def run_dijkstra(graph, src):
    dist = [INF] * V
    spt_set = [False] * V
    
    dist[src] = 0
    
    for count in range(V - 1):
        u = min_distance(dist, spt_set)
        spt_set[u] = True
        
        for v in range(V):
            if not spt_set[v] and graph[u][v] != 0 and dist[u] != INF and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
                
    print(f"Dijkstra Path distances from {src}:")
    for i in range(V):
        print(f"  Node {i}: {dist[i]}")

def main():
    graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ]
    run_dijkstra(graph, 0)

if __name__ == "__main__":
    main()
