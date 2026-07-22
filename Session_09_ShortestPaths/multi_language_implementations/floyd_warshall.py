# Session 09: Floyd-Warshall All-Pairs Shortest Path in Python

V = 4
INF = 999999

def run_floyd_warshall(graph):
    dist = [[graph[i][j] for j in range(V)] for i in range(V)]
    
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] != INF and dist[k][j] != INF and dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    
    print("Floyd-Warshall All-Pairs Matrix:")
    for i in range(V):
        for j in range(V):
            if dist[i][j] == INF:
                print("  INF", end="")
            else:
                print(f"{dist[i][j]:5}", end="")
        print()

def main():
    graph = [
        [0, 5, INF, 10],
        [INF, 0, 3, INF],
        [INF, INF, 0, 1],
        [INF, INF, INF, 0]
    ]
    run_floyd_warshall(graph)

if __name__ == "__main__":
    main()
