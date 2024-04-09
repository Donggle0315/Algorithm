import sys

def getState() :
    if kp > 0 :
        real[0][0] += 3
    elif kp < 0 :
        real[3][0] += 3
    else :
        real[0][0] += 1
        real[3][0] += 1
    if gu > 0 :
        real[2][0] += 3
    elif gu < 0 :
        real[1][0] += 3
    else :
        real[2][0] += 1
        real[1][0] += 1
        
        
        

#한국-포르투갈 / 가나-우루과이
#득점, 실점, 승점 : 한,우,가,포
#승점 -> 득실차 -> 득점 -> 재경기
data = [list(map(int, sys.stdin.readline().split())) for _ in range(4)]
real = [[] for _ in range(4)]
for idx in range(4) :
    real[idx][0] = data[idx][2]
    real[idx][1] = data[idx][0] - data[idx][1]
    real[idx][2] = data[idx][0]
kp = 0
gu = 0
n = int(sys.stdin.readline())

for _ in range(n) :
    country = sys.stdin.readline()
    if country == "korea" :
        kp += 1
    elif country == "portugal" :
        kp -= 0
    elif country == "uruguay" :
        gu -= 1
    else :
        gu += 1
    print(getState())