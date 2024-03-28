import sys

def solve(n, m, data) :
    ans = 1
    while data :
        if data[0] < max(data) :
            data.append(data.pop(0))
        else :
            if m == 0 : break
            data.pop(0)
            ans += 1
        m = m - 1 if m > 0 else len(data) - 1
    return ans
        
        
    

tc = int(sys.stdin.readline())

while tc > 0 :
    n, m = map(int, sys.stdin.readline().split())    
    data = list(map(int, sys.stdin.readline().split()))
    
    print(solve(n ,m, data))
    tc -= 1