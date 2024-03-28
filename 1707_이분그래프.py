import sys
sys.setrecursionlimit(10**6)

def dfs(graph, visited, start, flag) :
    visited[start] = flag
    for next in graph[start] :
        if not visited[next] :
            res = dfs(graph, visited, next, -flag)
            if not res : return False
        elif visited[next] == flag :
            return False
    return True

tc = int(sys.stdin.readline())

while tc :
    v, e = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(v + 1)]
    for _ in range(e) :
        e1, e2 = map(int, sys.stdin.readline().split())
        graph[e1].append(e2)
        graph[e2].append(e1)
    visited = [0] * (v + 1)
    cnt = 0
    for i in range(1, v + 1) :
        if not visited[i] :
            res = dfs(graph, visited, i, 1)
            if not res : break
    print("YES") if res else print("NO")
    tc -= 1