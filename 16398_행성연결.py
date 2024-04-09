import sys, heapq

def prim(start) :
    heap = []
    connected = [False] * n
    costSum = 0
    
    heapq.heappush(heap, (0, start))
    
    while heap :
        cost, v = heapq.heappop(heap)
        if not connected[v] :
            connected[v] = True
            costSum += cost
            for i in range(n) :
                if data[v][i] != 0 and not connected[i] :
                    heapq.heappush(heap, (data[v][i], i))

    return costSum

n = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

print(prim(0))