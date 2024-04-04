import sys
sys.setrecursionlimit(10**6)

def dfs_dp(start) :
    visited[start] = True
    if len(data[start]) == 1 and visited[data[start][0]] :
        dp[start] = 1
        return
    for next in data[start] :
        if visited[next] : continue
        dfs_dp(next)
        dp[start] += dp[next]
    dp[start] += 1

n, r, q = map(int, sys.stdin.readline().split())

data = [[] for _ in range(n+1)]
dp = [0] * (n + 1)
visited = [False] * (n + 1)
for _ in range(n-1) :
    u, v = map(int, sys.stdin.readline().split())
    data[u].append(v)
    data[v].append(u)
dfs_dp(r)
for _ in range(q) :
    query = int(sys.stdin.readline())
    print(dp[query])