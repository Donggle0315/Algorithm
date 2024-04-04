import sys

r,c,t = map(int, sys.stdin.readline().split())
data = [[[0] * c for _ in range(r)] for _ in range(t + 1)]
cleaner = []
delta = [(-1, 0), (1, 0), (0, -1), (0, 1)]
for i in range(r):
    line = list(map(int, sys.stdin.readline().split()))
    for j in range(c) :
        data[0][i][j] = line[j]
        if data[0][i][j] == -1 :
            cleaner.append((i,j))

for time in range(t) :
    #확산
    for i in range(r) :
        for j in range(c) :
            if data[time][i][j] < 5 : 
                data[time+1][i][j] += data[time][i][j]
                continue
            divide = data[time][i][j] // 5
            for dr, dc in delta :
                moveRow = i + dr
                moveCol = j + dc
                if moveRow < 0 or moveRow >= r or moveCol < 0 or moveCol >= c : continue
                if data[0][moveRow][moveCol] == -1 : continue
                data[time + 1][moveRow][moveCol] += divide
                data[time][i][j] -= divide
            data[time + 1][i][j] += data[time][i][j]
    
    #청정
    row = min(cleaner[0][0], cleaner[1][0])
    col = cleaner[0][1]
    next = 0
    for di in range(col+1, c) : #우
        tmp = data[time + 1][row][di]
        data[time + 1][row][di] = next
        next = tmp
    for di in range(row - 1, -1, -1) : #상
        tmp = data[time + 1][di][c-1]
        data[time + 1][di][c-1] = next
        next = tmp
    for di in range(c-2, col - 1, -1) : #좌
        tmp = data[time + 1][0][di]
        data[time + 1][0][di] = next
        next = tmp
    for di in range(1, row) : #하
        tmp = data[time + 1][di][col]
        data[time + 1][di][col] = next
        next = tmp
    data[time + 1][row][col] = -1
    
    row = max(cleaner[0][0], cleaner[1][0])
    col = cleaner[0][1]
    next = 0
    for di in range(col+1, c) : #우
        tmp = data[time + 1][row][di]
        data[time + 1][row][di] = next
        next = tmp
    for di in range(row + 1, r) : #하
        tmp = data[time + 1][di][c-1]
        data[time + 1][di][c-1] = next
        next = tmp
    for di in range(c-2, col-1, -1) : #좌
        tmp = data[time + 1][r-1][di]
        data[time + 1][r-1][di] = next
        next = tmp
    for di in range(r-2, row, -1) : #상
        tmp = data[time + 1][di][col]
        data[time + 1][di][col] = next
        next = tmp
    
    data[time + 1][row][col] = -1 

sum = 0    
for line in data[t] :
    for ele in line :
        sum += ele
print(sum+2)
        
