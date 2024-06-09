import sys

def getScore(cnt) :
    re = 0
    for i in range(1, cnt + 1) :
        re += (i * (cnt - i + 1))
    return re

n = int(sys.stdin.readline())
line = sys.stdin.readline()

flag = False
cnt = 0
ans = 0

for word in line :
    if word == '2' and not flag :
        flag = True
        cnt = 1
    elif word == '2' :
        cnt += 1
    elif flag :
        ans += getScore(cnt)
        flag = False
if flag :
    ans += getScore(cnt)         
print(ans)
