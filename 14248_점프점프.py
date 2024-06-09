import sys    

def dfs(start) :
    visited[start] = True
    next = start + data[start]
    if next >= 0 and next < n and visited[next] == False :
        dfs(next)
    next = start - data[start]
    if next >= 0 and next < n and visited[next] == False :
        dfs(next)

n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))
s = int(sys.stdin.readline())

visited = [False] * n

dfs(s-1)

print(visited.count(True))