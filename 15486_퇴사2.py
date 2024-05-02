import sys

n = int(sys.stdin.readline())

data = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]

dp = [0] * (n + 2)

for idx in range(n, 0, -1) :
    if idx + data[idx - 1][0] > n + 1 :
        dp[idx] = dp[idx + 1]
    else :
        dp[idx] = max(dp[idx + 1], dp[idx + data[idx - 1][0]] + data[idx - 1][1])


print(dp[1])        