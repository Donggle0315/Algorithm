import sys, math

def isPrime(n) :
    if n == 1 : return False
    if n == 2 : return True
    for i in range(2, int(math.sqrt(n)) + 1) :
        if n % i == 0 : return False
    return True

data = list(map(int, sys.stdin.readline().split()))
m = data[0]; n = data[1]

for num in range(m, n + 1) :
    if isPrime(num) :
        print(num)
        
