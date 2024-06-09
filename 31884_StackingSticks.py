import sys

q = int(sys.stdin.readline())
board = dict()

for _ in range(q) :
    a, b = map(int, sys.stdin.readline().split())
    if a == 1 :
        maxValue = max(board.get(b,0), max(board.get(b + 1, 0), max(board.get(b + 2, 0), board.get(b + 3, 0))))
        board[b] = maxValue + 1
        board[b + 1] = maxValue + 1
        board[b + 2] = maxValue + 1
        board[b + 3] = maxValue + 1
    elif a == 2 :
        board[b] = board.get(b,0) + 4
    else :
        print(board.get(b, 0))
        