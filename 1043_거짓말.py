import sys

def find(x) :
    if x == parent[x] : return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y) :
    px = find(x)
    py = find(y)
    if px == py : return
    if height[px] < height[py] : px, py = py, px
    parent[py] = px
    if height[px] == height[py] : height[px] += 1
    
n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n + 1)]
height = [0] * (n + 1)

party = [[] for _ in range(m)]
data = list(map(int, sys.stdin.readline().split()))
trueNum = data[0]
trueList = data[1:]
if trueNum == 0 :
    print(m)
    for _ in range(m) :
        tmp = sys.stdin.readline()
    exit()
for person in trueList[1:] :
    union(trueList[0], person)

for i in range(m) :
    data = list(map(int, sys.stdin.readline().split()))
    partyNum = data[0]
    partyList = data[1:]
    party[i].append(partyList[0])
    for j in partyList[1:] :
        union(partyList[0], j)
        party[i].append(j)

truth = find(trueList[0])
cnt = 0
for ele in party :
    flag = True
    for person in ele :
        if find(person) == truth :
            flag = False
            break
    if flag == True :
        cnt += 1

print(cnt)
    