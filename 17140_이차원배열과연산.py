import sys
input = sys.stdin.readline

def rowCalculate(matrix) :
    maxRowSize = 0
    for idx in range(len(matrix)) :
        line = matrix[idx]
        dic = dict()
        for num in line :
            if (num == 0) : continue
            dic[num] = line.count(num)
        # 등장횟수 오름차순 -> 값 오름차순
        items = list(dic.items())
        items.sort(key = lambda x : (x[1], x[0]))
        newLine = []
        for element in items :
            newLine.extend([element[0], element[1]])
        matrix[idx] = newLine
        maxRowSize = max(maxRowSize, len(newLine))
    for line in matrix :
        while(len(line) != maxRowSize) :
            line.append(0)
    return matrix

def transpose(matrix) : 
    newMatrix = [[] for _ in range(len(matrix[0]))]
    for i in range(len(matrix)) :
        for j in range(len(matrix[i])) :
            newMatrix[j].append(matrix[i][j])
    return newMatrix

def colCalculate(matrix) :
    transMatrix = transpose(matrix)
    colMatrix = rowCalculate(transMatrix)
    ans = transpose(colMatrix)
    return ans
    
def sliceList(matrix) :
    if (len(matrix) > 100) :
        matrix = matrix[:100]
    elif (len(matrix[0]) > 100) :
        for i in range(len(matrix)) :
            matrix[i] = matrix[i][:100]
    return matrix     

r,c,k = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(3)]

second = 0
while second <= 100 :
    if (len(matrix) >= r and len(matrix[0]) >= c and matrix[r-1][c-1] == k) : break
    if (len(matrix) >= len(matrix[0])) :
        matrix = rowCalculate(matrix)
    else :
        matrix = colCalculate(matrix)
    second += 1
    # for line in matrix :
    #     print(line)
    # print()
    matrix = sliceList(matrix)
if second == 101 : second = -1
print(second)