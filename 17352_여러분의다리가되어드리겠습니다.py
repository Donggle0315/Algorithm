import sys

def find(x) :
    if x == parent[x] : 
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y) :
    px = find(x)
    py = find(y)
    if px == py :
        return
    if height[px] < height[py] :
        px, py = py, px
    parent[py] = px
    if height[py] == height[px] :
        height[px] += 1


n = int(sys.stdin.readline())
parent = [i for i in range(n+1)]
height = [0] * (n + 1)

for _ in range(n - 2) :
    a, b = map(int, sys.stdin.readline().split())
    if a > b :
        b, a = a, b
    union(a, b)

for i in range(2 ,n + 1) :
    if find(1) != find(i) :
        print(1,i)
        break