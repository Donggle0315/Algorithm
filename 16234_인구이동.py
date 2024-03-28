import sys, math
sys.setrecursionlimit(10**6)

n, l, r = map(int, sys.stdin.readline().split())
data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

def movePopulation(unions) :
    changed = False 
    for union in unions :
        sum = 0
        for i, j in union :
            sum += data[i][j]
        avg = sum // len(union)
        for i, j in union :
            if data[i][j] != avg : 
                changed = True
            data[i][j] = avg
    return changed

def makeUnion(row, col, union, visited) : 
    delta = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    visited[row][col] = True
    union.append((row, col))
    for dx, dy in delta :
        nRow = row + dx
        nCol = col + dy
        if nRow < 0 or nRow >= n or nCol < 0 or nCol >= n : continue
        if (nRow, nCol) in union : continue
        diff = abs(data[row][col] - data[nRow][nCol]) 
        if diff < l or diff > r : continue
        union.append((nRow, nCol))
        makeUnion(nRow, nCol, union, visited)
    
    
def solve() :
    day = 0
    while True :
        unions = []
        visited = [[False] * n for _ in range(n)]
        for i in range(n) :
            for j in range(n) :
                if visited[i][j] : continue
                union = []
                makeUnion(i, j, union, visited)
                union = list(set(union))
                unions.append(union)
        
        
        if movePopulation(unions) == False :
            return day
        day += 1

print(solve())

