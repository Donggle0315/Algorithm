import sys

while True :
    n = int(sys.stdin.readline())
    if n == -1 : break
    
    sum = 1
    arr = []
    for i in range(2, n) :
        if n % i == 0 :
            arr.append(i)
            sum += i
    
    if sum == n and sum != 1:
        print(n, "= 1", end = '')
        for i in arr :
            print(" + %d"%(i), end = '')
        print()
    else :
        print(n, "is NOT perfect.")