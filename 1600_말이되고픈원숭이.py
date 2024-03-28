import sys
from collections import deque

INF = sys.maxsize

k = int(sys.stdin.readline())
w, h = map(int, sys.stdin.readline().split())
data = [list(map(int, sys.stdin.readline().split())) for _ in range(h)]
queue = deque()
dp = [[[INF] * w for _ in range(h)] for _ in range(k + 1)]

delta = [(0, 1, 0) , (0, -1, 0), (0, 0, 1), (0, 0, -1)
         ,(1, -1, -2), (1, -2, -1), (1, -2, 1), (1, -1, 2)
         ,(1, 1, -2), (1, 2, -1), (1, 2, 1), (1, 1, 2)]
queue.append((0,0,0))
dp[0][0][0] = 0
while queue :
    depth, row, col = queue.popleft()
    for dd, dr, dc in delta :
        md = depth + dd
        mr = row + dr
        mc = col + dc
        if md > k or mr < 0 or mr >= h or mc < 0 or mc >= w : continue
        if data[mr][mc] : continue
        if dp[md][mr][mc] <= dp[depth][row][col] + 1 : continue
        dp[md][mr][mc] = dp[depth][row][col] + 1
        queue.append((md, mr, mc))
        
    
minValue = INF
for i in range(k + 1) :
    minValue = min(minValue, dp[i][h-1][w-1])
if minValue == INF : minValue = -1

print(minValue)