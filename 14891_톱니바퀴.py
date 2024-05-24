import sys

def rotateWheel(data, rotate) :
    for i in range(1, 5) :
        if rotate[i] == 1 :
            temp = data[i][7]
            for j in range(6, -1 , -1) :
                data[i][j + 1] = data[i][j]
            data[i][0] = temp
        elif rotate[i] == -1 :
            temp = data[i][0]
            for j in range(0, 7) :
                data[i][j] = data[i][j+1]
            data[i][7] = temp

data = [[]]
for _ in range(4) :
    line = sys.stdin.readline().strip()
    data.append([i for i in line])

k = int(sys.stdin.readline())
command = [list(map(int, sys.stdin.readline().split())) for _ in range(k)]

for num, dir in command :
    rotate = [0, 0, 0 ,0, 0]
    rotate[num] = dir
    for idx in range(num, 4) :
        if data[idx][2] != data[idx + 1][6] :
            rotate[idx + 1] = rotate[idx] * -1
    for idx in range(num, 1, -1) :
        if data[idx][6] != data[idx - 1][2] :
            rotate[idx - 1] = rotate[idx] * -1
    
    rotateWheel(data, rotate)

ans = 0
if data[1][0] == '1' : ans += 1
if data[2][0] == '1' : ans += 2
if data[3][0] == '1' : ans += 4
if data[4][0] == '1' : ans += 8

print(ans)