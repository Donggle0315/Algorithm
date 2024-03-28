import sys, statistics

count = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))

maxScore = max(data)
ans = [i / maxScore * 100 for i in data]
print(statistics.mean(ans))