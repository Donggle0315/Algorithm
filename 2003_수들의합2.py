import sys

n, m = map(int, sys.stdin.readline().split())

data = list(map(int, sys.stdin.readline().split()))
data = [0] + data
for idx in range(1, n + 1) :
    data[idx] = data[idx] + data[idx - 1]

left = 0
right = 0
ans = 0

while left != (n + 1) and right != (n + 1) :
    value = data[right] - data[left]
    if value == m :
        ans += 1
        right += 1
    elif value < m :
        right += 1
    elif value > m :
        left += 1
print(ans)