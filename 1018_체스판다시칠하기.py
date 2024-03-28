import sys

def countChange(board, startRow, startCol) :
    blackCount = 0
    whiteCount = 0
    for row in range(startRow, startRow + 8) :
        for col in range(startCol, startCol + 8) :
            if ((row + col) % 2 == 1) and (board[row][col] != 'B') :
                blackCount += 1
            elif ((row + col) % 2 == 0) and (board[row][col] != 'W') :
                blackCount += 1
            elif ((row + col) % 2 == 0) and (board[row][col] != 'B') :
                whiteCount += 1
            elif ((row + col) % 2 == 1) and (board[row][col] != 'W') :
                whiteCount += 1
            
    return min(blackCount, whiteCount)

row, col = map(int, sys.stdin.readline().split())

board = []
for i in range(row) :
    board.append(sys.stdin.readline())
    
result = row * col
for i in range(row - 7) :
    for j in range(col - 7) :
        result = min(result, countChange(board, i, j))
print(result)