import sys

INF = sys.maxsize

def bellman_ford(start) :
    distance[start] = 0
    
    for i in range(n) :
        for j in range(m) :
            start, end, weight = edges[j]
            
            if distance[start] != INF and distance[end] > distance[start] + weight :
                distance[end] = distance[start] + weight
                if i == n - 1 : return True
    return False

n, m = map(int, sys.stdin.readline().split())
edges = []
distance = [INF] * (n + 1)

for _ in range(m) :
    s, e, w = map(int, sys.stdin.readline().split())
    edges.append((s,e,w))

result = bellman_ford(1)
if result : print("-1")
else :
    for i in range(2, n + 1) :
        if distance[i] == INF : print("-1")
        else : print(distance[i])