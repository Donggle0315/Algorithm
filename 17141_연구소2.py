import sys, itertools
from collections import deque

def bfs(queue) :
    while queue :
        row, col = deque.popleft(queue)
        for di, dj in delta :
            nextRow = row + di
            nextCol = col + dj
            if nextRow < 0 or nextRow >= n or nextCol < 0 or nextCol >= n : continue
            if data[nextRow][nextCol] == 1 : continue
            if visited[nextRow][nextCol] <= visited[row][col] + 1 : continue
            visited[nextRow][nextCol] = visited[row][col] + 1
            deque.append(queue, (nextRow, nextCol))

def findMaxValue(visited) :
    maxValue = 0
    for i in range(n) :
        for j in range(n) :
            if data[i][j] == 1 : continue
            if visited[i][j] == INF : 
                return INF
            maxValue = max(maxValue, visited[i][j])
    return maxValue

INF = sys.maxsize
n,m = map(int, sys.stdin.readline().split())
delta = [(-1, 0), (1, 0), (0, -1), (0, 1)]
data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
virus = []

for row in range(n) :
    for col in range(n) :
        if data[row][col] == 2 :
            virus.append((row, col))
            data[row][col] = 0

permu = list(itertools.combinations(virus, m))
ans = INF
for case in permu :
    visited = [[INF] * n for _ in range(n)]
    queue = deque()
    for ele in case :
        deque.append(queue, ele)
        visited[ele[0]][ele[1]] = 0
    bfs(queue)
    ans = min(ans, findMaxValue(visited))

if ans == INF : print(-1)
else : print(ans)