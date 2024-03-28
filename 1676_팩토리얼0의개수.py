import sys

n = int(sys.stdin.readline())
cnt = 0
for i in range(1,n+1) :
    tmp = i
    while (tmp % 5) == 0 :
        cnt += 1
        tmp /= 5
print(cnt)