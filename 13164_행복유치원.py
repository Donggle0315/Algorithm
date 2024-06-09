import sys

n, k = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split()))

## 격차가 큰 순서대로 

gaps = []
for i in range(len(data)-1):    
    gaps.append(data[i + 1] - data[i])    
gaps.sort()
    
if k > 1:    
    ans = sum(gaps[:-k + 1])
else:  
    ans = sum(gaps)
print(ans)