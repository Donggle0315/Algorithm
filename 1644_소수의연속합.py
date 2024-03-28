import sys, math

def getPrimes(last) :
    data = [True] * (last)
    data[0] = data[1] = False
    for i in range(2, int(math.sqrt(last)) + 2) :
        if data[i] == False : continue
        for j in range(2*i, last, i) :
            data[j] = False
    primes = []
    for i in range(last) :
        if data[i] : primes.append(i)
    return primes

n = int(sys.stdin.readline())
if n == 1 :
    print(0)
    exit()
primes = getPrimes(n + 1)

accum = [0]
for i in range(len(primes)) :
    accum.append(accum[i] + primes[i])

start = 0
end = 0
cnt = 0
while start < len(accum) :
    diff = accum[start] - accum[end]
    if diff == n :
        cnt += 1
        start += 1
    else :
        if end >= start or diff < n: 
            start += 1
        else :
            end += 1
print(cnt)