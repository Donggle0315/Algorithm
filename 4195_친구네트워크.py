import sys

def find(x) :
    if x == dic[x] : return x
    dic[x] = find(dic[x])
    return dic[x]

def union(x, y) :
    px = find(x)
    py = find(y)
    if px == py : return
    dic[py] = px
    height[px] += height[py]
    

tc = int(sys.stdin.readline())

while tc :
    f = int(sys.stdin.readline())
    dic = dict()
    height = dict()
    for _ in range(f) :
        f1, f2 = sys.stdin.readline().split()
        if f1 not in dic :
            dic[f1] = f1
            height[f1] = 1
        if f2 not in dic :
            dic[f2] = f2
            height[f2] = 1
            
        union(f1, f2)
        
        print(height[find(f1)])
    tc -= 1