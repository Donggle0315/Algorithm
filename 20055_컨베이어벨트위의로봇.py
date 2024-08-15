import sys
input = sys.stdin.readline

def rotateBelt(beltHead, n) :
    beltHead -= 1
    if beltHead < 0 :
        beltHead = 2 * n - 1
    return beltHead

def removeRobot(robot, belt, beltHead, n) :
    tail = beltHead + n - 1
    
    if tail >= 2 * n :
        tail -= 2 * n
    if robot[tail] == True :
        robot[tail] = False
    return robot, belt
    
def moveRobot(robot, belt, beltHead, n) :
    for i in range(n - 2, -1, -1) :
        now = beltHead + i
        next = now + 1
        if now >= 2 * n : now -= (2 * n)
        if next >= 2 * n : next -= (2 * n)
        
        if robot[now] == True and robot[next] == False and belt[next] > 0 :
            robot[now] = False
            robot[next] = True
            belt[next] -= 1
    return robot, belt
    
def placeRobot(robot, belt, beltHead) :
    if belt[beltHead] > 0 and robot[beltHead] == False :
        robot[beltHead] = True
        belt[beltHead] -= 1
    return robot, belt

def checkFinishCond(belt, n, k) :
    cnt = 0
    for i in range(0, 2*n) :
        if belt[i] <= 0 :
            cnt += 1
    return cnt >= k
    
n, k = map(int, input().split())
belt = list(map(int, input().split()))
robot = [False] * (2 * n)
stage = 1
beltHead = 0

while True :
    beltHead = rotateBelt(beltHead, n)
    robot, belt = removeRobot(robot, belt, beltHead, n)
    robot, belt = moveRobot(robot, belt, beltHead, n)
    robot, belt = removeRobot(robot, belt, beltHead, n)
    robot, belt = placeRobot(robot, belt, beltHead)
    if checkFinishCond(belt, n, k) :
        break
    stage += 1

print(stage)