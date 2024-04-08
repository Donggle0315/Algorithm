import sys

INF = sys.maxsize

def getSmallIndex() :
    min = INF
    idx = 1
    for i in range(1, n + 1) :
        if distance[i] < min and not visited[i] :
            min = distance[i]
            idx = i
    return idx

def dijkstra(start) :
    for i in range(1, n + 1) :
        distance[i] = data[start][i]
    
    visited[start] = True
    for i in range(n - 2) :
        current = getSmallIndex()
        visited[current] = True
        for j in range(1, n + 1) :
            if not visited[j] :
                distance[j] = min(distance[j], distance[current] + data[current][j])
                
                
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

data = [[INF] * (n + 1) for _ in range(n + 1)]
visited = [False] * (n + 1)
distance = [INF] * (n + 1)
for _ in range(m) :
    s, e, v = map(int, sys.stdin.readline().split())
    data[s][e] = min(data[s][e], v)
    
start, finish = map(int, sys.stdin.readline().split())
dijkstra(start)
print(distance[finish])