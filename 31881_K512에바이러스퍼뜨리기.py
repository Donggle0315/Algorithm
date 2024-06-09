import sys

n, q = map(int, sys.stdin.readline().split())

virus = set()

for _ in range(q) :
    line = list(map(int, sys.stdin.readline().split()))
    if line[0] == 1 :
        virus.add(line[1])
    elif line[0] == 2 :
        virus.discard(line[1])
    else :
        print(n - len(virus))
    