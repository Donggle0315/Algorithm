import sys

n = map(int, sys.stdin.readline())
data = set(map(int, sys.stdin.readline().split()))
data = list(data)
data.sort()

for i in data :
    print(i, end=' ')