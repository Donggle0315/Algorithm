import sys
def moveDice(dice, direction) :
    #  2     2     2     6     1
    #4 1 3 1 3 6 6 4 1 4 2 3 4 5 3
    #  5     5     5     1     6
    #  6     4     3     5     2
    if direction == 1 : #east
        dice[1], dice[3], dice[4], dice[6] = dice[3], dice[6], dice[1], dice[4]
    elif direction == 2 : #west
        dice[1], dice[3], dice[4], dice[6] = dice[4], dice[1], dice[6], dice[3]
    elif direction == 3 : #north
        dice[1], dice[2], dice[5], dice[6] = dice[2], dice[6], dice[1], dice[5]
    else : #south
        dice[1], dice[2], dice[5], dice[6] = dice[5], dice[1], dice[6], dice[2]
               
n,m,y,x,k = map(int, sys.stdin.readline().split())

data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
command = list(map(int, sys.stdin.readline().split()))

dice = [0, 0, 0, 0, 0, 0, 0]
dir = [[0,0], [0,1], [0,-1], [-1,0],[1,0]]
for idx in command :
    nextX = x + dir[idx][1]
    nextY = y + dir[idx][0]
    
    if nextX < 0 or nextX >= m or nextY < 0 or nextY >= n :
        continue
    
    #변경하고 돌리기
    moveDice(dice, idx)
    x = nextX
    y = nextY
    
    if data[y][x] == 0 :
        data[y][x] = dice[1]
    else :
        dice[1] = data[y][x]
        data[y][x] = 0
    
    print(dice[6])