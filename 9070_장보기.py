import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    start=100001
    ans=0
    money = 0
    for j in range(int(sys.stdin.readline())):
        a, b=map(int, sys.stdin.readline().split())
 
        if start > b/a :
            start=b/a
            money=b
        elif start == b/a:
            money = min(money, b)
    print(money)
