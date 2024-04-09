import sys

def dfs(idx, visited, depth) :
    visited[idx] = True
    maxValue = depth
    
    for next in edges[idx] :
        if visited[next] : continue
        dp = dfs(next, visited, depth + 1)
        maxValue = max(dp, maxValue)
    return maxValue

n, m = map(int, sys.stdin.readline().split())

edges = [[] for _ in range(n)]

for _ in range(m) :
    a, b = map(int, sys.stdin.readline().split())
    edges[a].append(b)
    edges[b].append(a)

for i in range(n) :
    visited = [False] * n
    result = dfs(i, visited, 1)
    if result == True :
        print(1)
        exit()
print(0)