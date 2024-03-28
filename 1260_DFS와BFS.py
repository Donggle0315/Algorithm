import sys
from collections import deque

def dfs(edges, visited, vertex) :
    visited[vertex] = True
    print(vertex, end = ' ')
    for next in edges[vertex] :
        if not visited[next] :
            dfs(edges, visited, next)
            
def bfs(edges, visited, vertex) :
    queue = deque([vertex])
    visited[vertex] = True
    
    while queue :
        now = queue.popleft()
        print(now, end = ' ')
        for next in edges[now] :
            if not visited[next] :
                queue.append(next)
                visited[next] = True
        
    

n, m, v = map(int, sys.stdin.readline().split())

edges = [[] for _ in range(n+1)]
for i in range(m) :
    e1, e2 = map(int, sys.stdin.readline().split())
    edges[e1].append(e2)
    edges[e2].append(e1)
for edge in edges :
    edge.sort()

visited = [False] * (n+1)
dfs(edges, visited, v)
print()
visited = [False] * (n+1)
bfs(edges, visited, v)
print()