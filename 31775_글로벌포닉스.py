import sys

data = [sys.stdin.readline() for _ in range(3)]

cnt = 0
for i in data :
    if i[0] == 'k' : cnt += 1
    elif i[0] == 'l' : cnt += 2
    elif i[0] == 'p' : cnt += 4

if cnt == 7 : print("GLOBAL")
else : print("PONIX")
    
