import sys, math, bisect

data = [True] * 1299710
data[0] = data[1] = False
primes = []

for i in range(2, int(math.sqrt(1299710) + 1)) :
    if data[i] == False : continue
    for j in range(i * 2, 1299710, i) :
        data[j] = False
for i in range(2, 1299710) :
    if data[i] == True :
        primes.append(i)

tc = int(sys.stdin.readline())
for _ in range(tc) :
    n = int(sys.stdin.readline())
    if n == 1 : 
        print(0)
        continue

    idx = bisect.bisect_left(primes, n)
    if primes[idx] == n : 
        print(0)
        continue
    idx -= 1
    print(primes[idx + 1] - primes[idx])
    
    
        