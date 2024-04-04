import sys

def find(x) :
    if x == parent[x] : return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y) :
    nx = find(x)
    ny = find(y)
    if nx == ny :
        return
    if height[nx] < height[ny] :
        nx, ny = ny, nx
    parent[ny] = nx
    if height[nx] == height[ny] :
        height[ny] += 1

n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n + 1)]
height = [0] * (n+1)
for _ in range(m) :
    mode, a, b = map(int, sys.stdin.readline().split())
    if mode == 0 :
        union(a,b)
    elif find(a) == find(b) :
        print("YES")
    else :
        print("NO")
    