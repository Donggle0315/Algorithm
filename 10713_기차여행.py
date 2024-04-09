import sys

n, m = map(int, sys.stdin.readline().split())
ps = list(map(int, sys.stdin.readline().split()))
pay = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n - 1)]

mov = [0] * (n + 1)

for day in range(m - 1) :
    start = ps[day]
    end = ps[day + 1]
    
    # if start < end :
    #     for i in range(start, end) :
    #         mov[i] += 1
    # else :
    #     for i in range(start, end, -1) :
    #         mov[i-1] += 1
    if start < end :
        mov[end] -= 1
        mov[start] += 1
    else :
        mov[end] += 1
        mov[start] -= 1
    
for i in range(1, len(mov)) :
    mov[i] = mov[i - 1] + mov[i]
    
ans = 0
for i in range(1,n) :
    a,b,c = pay[i - 1]
    rep = mov[i]
    
    ans += min(rep * a, rep * b + c)
print(ans)
    