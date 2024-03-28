import sys, itertools

while True :
    data = list(map(int, sys.stdin.readline().split()))
    if data[0] == 0 : break
    
    n = data[0]
    candidate = data[1:]
    
    combination = list(itertools.combinations(candidate, 6))
    for i in combination :
        for j in i :
            print(j, end=' ')
        print()
    print()