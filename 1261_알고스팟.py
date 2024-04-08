import sys, heapq

INF = sys.maxsize
delta = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def dijkstra(row, col) :
    distance[row][col] = 0
    heap = []
    heapq.heappush(heap, (0, row, col))
    
    while heap :
        weight, row, col = heapq.heappop(heap)
        if distance[row][col] < weight : continue
        
        for nextRow, nextCol, w in edges[row][col] :
            if distance[nextRow][nextCol] > w + distance[row][col] :
                distance[nextRow][nextCol] = w + distance[row][col]
                heapq.heappush(heap, (distance[nextRow][nextCol], nextRow, nextCol))

m, n = map(int, sys.stdin.readline().split())
lines = [sys.stdin.readline() for _ in range(n)]
edges = [[[] for _ in range(m)] for _ in range(n)]
distance = [[INF] * m for _ in range(n)]
for i in range(n) :
    for j in range(m) :
        for dr, dc in delta :
            nr = i + dr
            nc = j + dc
            if nr < 0 or nr >= n or nc < 0 or nc >= m : continue
            if lines[nr][nc] == '1' : 
                edges[i][j].append((nr, nc, 1))
            else :
                edges[i][j].append((nr, nc, 0))
                
dijkstra(0,0)
print(distance[n-1][m-1])