import sys

n, m = map(int, sys.stdin.readline().split())

data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

gaps = []
bad = 0
for i in range(1, n) :
    tmp = 0
    for j in range(m) :
        tmp += abs(data[0][j] - data[i][j])
    if tmp > 2000 : 
        bad += 1
        
if bad * 2 >= n - 1 or bad != 0 :
    print("YES")
else :
    print("NO")