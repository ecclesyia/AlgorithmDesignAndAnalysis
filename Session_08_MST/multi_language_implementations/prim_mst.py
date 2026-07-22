# Session 08: Prim's Minimum Spanning Tree (MST) in Python

V = 5
INF = 999999

def min_key(key, mst_set):
    min_val = INF
    min_index = -1
    for v in range(V):
        if not mst_set[v] and key[v] < min_val:
            min_val = key[v]
            min_index = v
    return min_index

def run_prim(graph):
    parent = [0] * V
    key = [INF] * V
    mst_set = [False] * V
    
    key[0] = 0
    parent[0] = -1
    
    for count in range(V - 1):
        u = min_key(key, mst_set)
        mst_set[u] = True
        
        for v in range(V):
            if graph[u][v] != 0 and not mst_set[v] and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]
                
    print("Prim's MST:")
    cost = 0
    for i in range(1, V):
        print(f"  {parent[i]} - {i} == {graph[i][parent[i]]}")
        cost += graph[i][parent[i]]
    print(f"Total Cost: {cost}")

def main():
    graph = [
        [0, 2, 0, 6, 0],
        [2, 0, 3, 8, 5],
        [0, 3, 0, 0, 7],
        [6, 8, 0, 0, 9],
        [0, 5, 7, 9, 0]
    ]
    run_prim(graph)

if __name__ == "__main__":
    main()
