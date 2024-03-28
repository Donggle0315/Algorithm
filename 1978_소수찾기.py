import sys

def isPrime(n) : 
    if n == 1 : return 0
    if n == 2 : return 1
    for i in range(2,n) :
        if n % i == 0 : return 0
    return 1

n = map(int, sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))
ans = 0

for num in data :
    ans += isPrime(num)    
print(ans)