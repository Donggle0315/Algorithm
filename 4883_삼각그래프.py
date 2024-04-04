import sys
INF = sys.maxsize
tc = 1
while True : 
    n = int(sys.stdin.readline())
    if n == 0 : break
    
    data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    dp = [[0] * 3 for _ in range(n)]
    dp[0][0] = INF
    dp[0][1] = data[0][1]
    dp[0][2] = data[0][2] + data[0][1]
    
    for i in range(1, n) :
        dp[i][0] = data[i][0] + min(dp[i-1][0], dp[i-1][1])
        dp[i][1] = data[i][1] + min(dp[i-1][0], min(dp[i][0], min(dp[i-1][1], dp[i-1][2])))
        dp[i][2] = data[i][2] + min(dp[i-1][1], min(dp[i][1], dp[i-1][2]))
    
    print(str(tc) + ". " + str(dp[n-1][1]))
    tc += 1