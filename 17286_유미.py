import sys, math

coor = [list(map(int, sys.stdin.readline().split())) for _ in range(4)]
distance = [[0] * 4 for _ in range(4)]
for i in range(4) :
    for j in range(i) :
        if i == j : continue
        dx = coor[i][0] - coor[j][0]
        dy = coor[i][1] - coor[j][1]
        distance[i][j] = math.sqrt(dx*dx + dy*dy)
        distance[j][i] = distance[i][j]
        
arr = [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
ans = 1000000.0
for a,b,c in arr :
    dis = distance[0][a] + distance[a][b] + distance[b][c]
    ans = min(dis, ans)

print(int(ans))
