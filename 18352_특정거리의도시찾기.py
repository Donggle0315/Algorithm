import sys, heapq

INF = sys.maxsize

def dijkstra(start) :
    heap = []
    heapq.heappush(heap, (0, start))
    distance[start] = 0
    
    while heap :
        w, now = heapq.heappop(heap)
        if distance[now] < w : continue
        
        for next in edges[now] :
            if distance[next] > w + 1 :
                distance[next] = w + 1
                heapq.heappush(heap, (distance[next], next))


n, m, k, x = map(int, sys.stdin.readline().split())
distance = [INF] * (n + 1)
edges = [[] for _ in range(n + 1)]

for _ in range(m) :
    s, e = map(int, sys.stdin.readline().split())
    edges[s].append(e)
    
dijkstra(x)
for i in range(1, n + 1) :
    if distance[i] == k : print(i)
if distance.count(k) == 0 : print(-1)