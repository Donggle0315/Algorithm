import sys

a, b = map(int, sys.stdin.readline().split())

n = int(sys.stdin.readline())

reserve = [int(sys.stdin.readline()) for _ in range(n)]

minValue = abs(a - b)
for ele in reserve :
    minValue = min(minValue, 1 + abs(ele-b))
    
print(minValue)