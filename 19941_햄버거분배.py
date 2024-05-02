import sys

n, k = map(int, sys.stdin.readline().split())
tmp = sys.stdin.readline()
string = []
for i in tmp :
    string.append(i)
cnt = 0
for idx in range(n) :
    if string[idx] != 'P' : continue
    start = idx - k
    if start < 0 : start = 0
    end = idx + k
    if end >= len(string) : end = len(string) - 1
    
    for pos in range(start, end + 1) :
        if string[pos] == 'H' :
            string[pos] = 'X'
            cnt += 1
            break
        
print(cnt)