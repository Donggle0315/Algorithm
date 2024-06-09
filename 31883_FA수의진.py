import sys

n = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
## 횡단보도 육교 녹색 적색
time = 0

for a,b,c,d in data :
    tmp = time % (c + d)
    if tmp < c :
        time += a
    elif c + d - tmp + a < b :
        time += (c + d - tmp + a)
    else :
        time += b
        
print(time)