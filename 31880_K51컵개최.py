import sys

n, m = map(int, sys.stdin.readline().split())

nData = list(map(int, sys.stdin.readline().split()))
mData = list(map(int, sys.stdin.readline().split()))

nData.sort()
mData.sort()

ans = sum(nData)

for num in mData :
    if num == 0 : 
        continue
    ans *= num
print(ans)             