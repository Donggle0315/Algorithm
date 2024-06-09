
import sys

n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))

data.sort()

p1 = 0
p2 = len(data) - 1
real = 0
ans = sys.maxsize
while p1 < p2 :
    length = data[p1] + data[p2]
    p3 = p1 + 1
    p4 = p2 - 1
    while p3 < p4 :
        length2 = data[p3] + data[p4]
        if ans > abs(length2 - length) :
            ans = abs(length2 - length)
            real = length2 - length
        if length2 < length :
            p3 += 1
        else :
            p4 -= 1
    if real > 0 :
        p1 += 1
    else :
        p2 -= 1
print(ans)
        
        