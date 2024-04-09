import sys

n, m = map(int, sys.stdin.readline().split())
queues = [[] for _ in range(200001)]

for i in range(1, n + 1) :
    line = list(map(int, sys.stdin.readline().split()))
    for ele in line[1:] :
        queues[ele].append(i)

serving = list(map(int, sys.stdin.readline().split()))

ans = [0] * (n + 1)
for bab in serving :
    if len(queues[bab]) == 0 : continue
    ans[queues[bab][0]] += 1
    queues[bab].pop(0)
    
for d in ans[1:] :
    print(d, end = ' ')
print()