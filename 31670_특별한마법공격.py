import sys

n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))

dp = [[0] * 2 for _ in range(n) ] 
#0th not kill 
#1st kill

dp[0][0] = 0
dp[0][1] = data[0]

for i in range(1, n) :
    dp[i][0] = dp[i-1][1]
    dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + data[i]

print(min(dp[n-1][0], dp[n-1][1]))