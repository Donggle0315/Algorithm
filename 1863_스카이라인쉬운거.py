import sys
from collections import deque

n = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

data.sort()
building = 0
stack = deque()
deque.append(stack, 0)
cnt = 1
for x, y in data :
    top = stack[cnt - 1]
    while top <= y :
        deque.pop(stack)
        cnt -= 1
        
    stack.append(stack, y)
    cnt += 1
    building += 1
    
print(building)