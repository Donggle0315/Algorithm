import sys

n, b = map(int, sys.stdin.readline().split())

data = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ans = ''

while n != 0 :
    ans = data[n % b] + ans
    n //= b
print(ans)