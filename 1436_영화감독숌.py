import sys

num = int(sys.stdin.readline())
start = 665
while num :
    start += 1
    if('666' in str(start)) : num -= 1
print(start)