import sys

n = int(sys.stdin.readline())

left = 10001
right = -10001
up = -10001
down = 10001

for _ in range(n) :
    a, b = map(int, sys.stdin.readline().split())
    left = min(left, a)
    right = max(right, a)
    up = max(up, b)
    down = min(down, b)
print((right - left) * (up - down))