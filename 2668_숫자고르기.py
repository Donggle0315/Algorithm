import sys
from collections import defaultdict

def dfs(u, visited):
    visited.add(u)
    checked[u] = 1
    for v in g[u]:
        if v not in visited:
            dfs(v, visited.copy())
        else: 
            ans.extend(list(visited))
            return

n = int(sys.stdin.readline().strip())
g = defaultdict(list)
for i in range(1, n+1):
    v = int(sys.stdin.readline().strip())
    g[v].append(i)

checked = [0 for _ in range(n+1)]
ans = []
for i in range(1, n+1):
    if not checked[i]:
        dfs(i, set([]))

ans.sort()
print(len(ans)) 
for x in ans:
    print(x)