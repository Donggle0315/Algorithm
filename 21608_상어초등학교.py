import sys
input = sys.stdin.readline
score = [0,1,10,100,1000]
dir = [[-1,0],[1,0],[0,-1],[0,1]]

def outOfRange(row, col, n) :
    if (row < 0 or row >= n) :
        return True
    if (col < 0 or col >= n) :
        return True
    return False 

n = int(input())
dic = dict()
data = []
classroom = [[0] * n for _ in range(n)]

for i in range(n*n) :
    line = list(map(int, input().split()))
    data.append([line[0], line[1:]])

for student in data :
    maxFriend = -1; maxEmpty = -1
    ansRow = -1; ansCol = -1
    for row in range(n) :
        for col in range(n) :
            empty = 0; friend = 0
            if classroom[row][col] != 0 :
                continue
            for i, j in dir :
                nextRow = row - i
                nextCol = col - j
                if (outOfRange(nextRow, nextCol, n)) : 
                    continue
                if (classroom[nextRow][nextCol] == 0) :
                    empty += 1
                if (classroom[nextRow][nextCol] in student[1]) :
                    friend +=1
            if friend > maxFriend :
                maxFriend = friend
                maxEmpty = empty
                ansRow = row
                ansCol = col
            elif friend == maxFriend and empty > maxEmpty :
                maxEmpty = empty
                maxFriend = friend
                ansRow = row
                ansCol = col
            elif ansRow == -1 and ansCol == -1 :
                ansRow = row
                ansCol = col
    classroom[ansRow][ansCol] = student[0]
    dic[student[0]] = [student[1], ansRow, ansCol]
       
ans = 0         
for line in classroom :
    for studentNum in line :            
        info, row, col = dic[studentNum]
        friend = 0
        for i, j in dir :
            nextRow = row + i
            nextCol = col + j
            if (outOfRange(nextRow, nextCol, n)) :
                continue
            if classroom[nextRow][nextCol] in info :
                friend += 1
        ans += score[friend]
        
print(ans)