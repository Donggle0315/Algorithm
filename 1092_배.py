import sys

n = int(sys.stdin.readline())
crain = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
box = list(map(int, sys.stdin.readline().split()))

crain.sort(reverse=True)
box.sort(reverse=True)

ans = 0
if crain[0] < box[0] :
    print(-1)
    exit()

while box :
    for c in crain :
        if box and c < box[len(box) - 1] :
            continue
        for b in box :
            if c >= b :
                box.remove(b)
                break
    ans += 1
print(ans)