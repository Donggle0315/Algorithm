import sys

DIV = 1000000

n = list(sys.stdin.readline().strip())
length = len(n)
dp = [0] * (length + 1)
dp[0] = 1
dp[1] = 1

if n[0] == '0' : 
    print(0)
    exit()

for idx in range(1, length) :
    if n[idx] == '0' :
        if n[idx - 1] != '1' and n[idx - 1] != '2' :
            print(0)
            exit()
        else :
            dp[idx + 1] = dp[idx - 1]
            dp[idx] = 0
    else :
        if int(n[idx - 1]) * 10 + int(n[idx]) <= 26 :
            dp[idx + 1] = (dp[idx - 1] + dp[idx]) % DIV
        else :
            dp[idx + 1] = dp[idx]

print(dp[-1] % DIV)
