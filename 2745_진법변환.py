import sys

n, b = sys.stdin.readline().split()
b = int(b)
data = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ans = 0
k = 0
for num in n[::-1] :
    ans += (data.index(num) * (b ** k))
    k += 1
print(ans)