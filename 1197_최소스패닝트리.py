import sys

def find(x) :
    if parent[x] == x :
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y) :
    px = find(x)
    py = find(y)
    if px == py : return
    
    if px < py : px, py = py, px
    parent[py] = px
    
def kruskal() :
    edges.sort()
    costSum = 0
    for cost, a, b in edges :
        if find(a) != find(b) :
            union(a, b)
            costSum += cost
    return costSum

n, m = map(int, sys.stdin.readline().split())
edges = []
parent = [i for i in range(0, n + 1)]
for _ in range(m) :
    a,b,w = map(int, sys.stdin.readline().split())
    edges.append((w,a,b))

print(kruskal())
