import sys

data = [0] * 11

for idx in range(1, 11) :
    num = int(sys.stdin.readline())
    data[idx] = data[idx-1] + num
    
    
ans = 0
for i in data :
    if abs(ans - 100) >= abs(i - 100) :
        ans = i
print(ans)