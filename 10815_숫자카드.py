import sys

n = map(int, sys.stdin.readline())
data = set(map(int, sys.stdin.readline().split()))

m = map(int, sys.stdin.readline())
target = list(map(int, sys.stdin.readline().split()))
for num in target :
    if num in data :
        print(1, end = ' ')
    else :
        print(0, end = ' ')    