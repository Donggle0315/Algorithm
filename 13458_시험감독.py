import sys

n = int(sys.stdin.readline())
candidate = list(map(int, sys.stdin.readline().split()))
b, c = map(int, sys.stdin.readline().split())

ans = 0
for i in range(n) :
    candidate[i] -= b
    ans += 1
    
for i in range(n) :
    if candidate[i] <= 0 :
        continue
    
    ans += (candidate[i] // c)
    if candidate[i] % c != 0 : 
        ans += 1
        
print(ans)