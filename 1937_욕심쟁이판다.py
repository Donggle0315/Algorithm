import sys
sys.setrecursionlimit(10**6)

n = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
delta = [(-1, 0), (1, 0), (0, -1), (0, 1)]
dp = [[0] * n for _ in range(n)]
maxDepth = 0

def dfs(row, col, depth) : 
    dp[row][col] = depth
    for di, dj in delta :
        moveRow = row + di
        moveCol = col + dj
        if moveRow < 0 or moveRow >= n or moveCol < 0 or moveCol >= n : continue
        if data[row][col] >= data[moveRow][moveCol] : continue
        if dp[moveRow][moveCol] > depth : continue
        dfs(moveRow, moveCol, depth + 1)


for i in range(n) :
    for j in range(n) :
        if dp[i][j] != 0 : continue
        dfs(i, j, 1)
for ele in dp :
    for num in ele :
        maxDepth = max(maxDepth, num)
print(maxDepth)