import sys
from collections import deque

class Stack:
    def __init__(self) :
        self.stack = deque()
        self.log = []
    
    def push(self, data) :
        self.stack.append(data)
        self.log.append('+')
        
    def pop(self) :
        self.log.append('-')
        return self.stack.pop()
      
    def isEmpty(self) :
        return len(self.stack) == 0
    
    def top(self) :
        return self.stack[-1]
    
n = int(sys.stdin.readline())
data = [int(sys.stdin.readline()) for i in range(n)]
stack = Stack()
flag = True
now = 1
idx = 0
for i in range(n) :
    k = data[idx]
    idx += 1
    while now <= k :
        stack.push(now)
        now += 1
    if stack.top() == k :
        tmp = stack.pop()
    else :
        flag = False
        

if flag == False :
    print("NO")
else : 
    for i in stack.log :
        print(i)
    