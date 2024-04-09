import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())

visited = [(0,0)] * 200000

q = deque()
deque.append(q, (n, n))
visited[n] = (n,0) 

while q :
    before, now = deque.popleft(q)
    time = visited[now][1]
    if now == k : break
    
    if 0 <= (now - 1) and visited[now - 1][1] == 0 : 
        deque.append(q, (now, now - 1))
        visited[now - 1] = (now, time + 1)
    if (now + 1) < 200000 and visited[now + 1][1] == 0 : 
        deque.append(q, (now, now + 1))
        visited[now + 1] = (now, time + 1)
    if (2 * now) < 200000 and visited[2 * now][1] == 0 : 
        deque.append(q, (now, now * 2))
        visited[now  * 2] = (now, time + 1)
        
    
    
idx = k
past = []
while idx != n :
    past.append(idx)
    idx = visited[idx][0]
past.append(n)

print(visited[k][1])
for ele in past[::-1] :
    print(ele, end = ' ')
print()