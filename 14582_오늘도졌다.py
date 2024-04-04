import sys

home = list(map(int, sys.stdin.readline().split()))
away = list(map(int, sys.stdin.readline().split()))

homeSum = 0
awaySum = 0

for i in range(9) :
    homeSum += home[i]
    if homeSum > awaySum : 
        print("Yes")
        exit()
    awaySum += away[i]
print("No")