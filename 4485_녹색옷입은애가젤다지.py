import sys, heapq

INF = sys.maxsize
delta = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def dijkstra(data, distance, sRow, sCol) :
    distance[sRow][sCol] = data[sRow][sCol]
    heap = []
    heapq.heappush(heap, (data[sRow][sCol], sRow, sCol))
    
    while heap :
        weight, row, col = heapq.heappop(heap)
        if distance[row][col] < weight : continue
        for di, dj in delta :
            nextRow = row + di
            nextCol = col + dj
            if nextRow < 0 or nextRow >= n or nextCol < 0 or nextCol >= n : continue
            nextWeight = weight + data[nextRow][nextCol]
            if nextWeight < distance[nextRow][nextCol] :
                distance[nextRow][nextCol] = nextWeight
                heapq.heappush(heap, (nextWeight, nextRow, nextCol))

cnt = 1
while True :
    n = int(sys.stdin.readline())
    if n == 0 : break
    
    data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    distance = [[INF] * n for _ in range(n)]
    dijkstra(data, distance, 0, 0)
    print("Problem %d: %d"%(cnt,distance[n-1][n-1]))
    cnt += 1