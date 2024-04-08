import sys, heapq

INF = sys.maxsize
delta = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def dijkstra(row, col) :
    heap = []
    heapq.heappush(heap, (0, row, col))
    distance[row][col] = 0
    
    while heap :
        w, row, col = heapq.heappop(heap)
        if distance[row][col] < w : continue
        
        for nextRow, nextCol, weight in edges[row][col] :
            if distance[nextRow][nextCol] > w + weight :
                distance[nextRow][nextCol] = w + weight
                heapq.heappush(heap, (distance[nextRow][nextCol], nextRow, nextCol))


n = int(sys.stdin.readline())
distance = [[INF] * n for _ in range(n)]
edges = [[[] for _ in range(n)] for _ in range(n)]

data = [sys.stdin.readline() for _ in range(n)]

for i in range(n) :
    for j in range(n) :
        for dr, dc in delta :
            nr = i + dr
            nc = j + dc
            if nr < 0 or nr >= n or nc < 0 or nc >= n : continue
            if data[nr][nc] == '0' :
                edges[i][j].append((nr, nc ,1))
            else :
                edges[i][j].append((nr, nc, 0))
    
dijkstra(0, 0)
print(distance[n-1][n-1])