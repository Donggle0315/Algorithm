import sys
import heapq

INF = sys.maxsize

def dijkstra(edges, distance, start) :
    distance[start] = 0
    heap = []
    heapq.heappush(heap, (0, start))
    
    while heap :
        weight, now = heapq.heappop(heap)
        if distance[now] < weight : continue
        for w, next in edges[now] :
            nextWeight = w + weight
            if nextWeight < distance[next] :
                distance[next] = nextWeight
                heapq.heappush(heap, (nextWeight, next))
    
v, e = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

edges = [[] for _ in range(v+1)]
for _ in range(e) :
    e1, e2, weight = map(int, sys.stdin.readline().split())
    edges[e1].append((weight, e2))
distance = [INF] * (v+1)
dijkstra(edges, distance, k)

for i in distance[1:] :
    if i == INF : print("INF")
    else : print(i)

