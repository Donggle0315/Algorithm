import sys

INF = sys.maxsize

def floydWashall() :
    for k in range(1, n + 1) :
        for i in range(1, n + 1) :
            for j in range(1, n + 1) :
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

n = int(sys.stdin.readline())
distance = [[INF] * (n + 1) for _ in range(n + 1)]
for i in range(n + 1) :
    distance[i][i] = 0
while True :
    e1, e2 = map(int, sys.stdin.readline().split())
    if e1 == -1 and e2 == -1 : break
    distance[e1][e2] = 1
    distance[e2][e1] = 1

floydWashall()
res = []
for ele in distance[1:] :
    res.append(max(ele[1:]))

ans = min(res)
ansCnt = res.count(ans)

print(ans, ansCnt)
for i in range(n) :
    if res[i] == ans :
        print(i + 1, end = ' ')
print()