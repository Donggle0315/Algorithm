import sys
INF = sys.maxsize

def floydWarshall(distance) : 
    for k in range(1, n + 1) :
        for i in range(1, n + 1) :
            for j in range(1, n + 1) :
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

graph = [[INF] * (n + 1) for _ in range(n + 1)]

for _ in range(m) :
    e1, e2, w = map(int, sys.stdin.readline().split())
    graph[e1][e2] = min(graph[e1][e2], w)
for i in range(1, n + 1) :
    graph[i][i] = 0

floydWarshall(graph)
for i in range(1, n + 1) :
    for j in range(1, n + 1) :
        print("0", end = ' ') if graph[i][j] == INF else print(graph[i][j], end = ' ')
    print()