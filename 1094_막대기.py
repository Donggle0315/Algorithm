import sys

n = int(sys.stdin.readline())

data = list(bin(n))
print(data.count('1'))