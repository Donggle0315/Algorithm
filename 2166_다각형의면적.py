import sys

n = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
data.append(data[0])


sum = 0
for i in range(n) :
    sum += (data[i][0] * data[i+1][1])
    sum -= (data[i][1] * data[i+1][0])
print(round(abs(sum/2),1))
