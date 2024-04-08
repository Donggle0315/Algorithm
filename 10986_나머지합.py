import sys

n, m = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split()))

prefix = [0] * (n + 1)
for idx in range(n) :
    prefix[idx + 1] = (prefix[idx] + data[idx]) % m

ans = 0
for i in range(m) :
    cnt = prefix.count(i)
    ans += (cnt * (cnt - 1)) // 2
print(ans)