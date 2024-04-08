import sys

def build(idx, start, end) :
    if start == end :
        segTree[idx] = (data[start - 1], data[start - 1])
        return 
    mid = (start + end) // 2
    build(idx * 2, start, mid)
    build(idx * 2 + 1, mid + 1, end)
    maxValue = max(segTree[idx * 2][0], segTree[idx * 2 + 1][0])
    minValue = min(segTree[idx * 2][1], segTree[idx * 2 + 1][1])
    segTree[idx] = (maxValue, minValue)
    
def query(idx, start, end, left, right, mode) : #mode = 0 max, mode = 1 min
    if right < start or end < left : 
        if mode == 0 : return 0
        else : return sys.maxsize
    if left <= start and end <= right : 
        if mode == 0 : return segTree[idx][0]
        else : return segTree[idx][1]
    
    mid = (start + end) // 2
    leftChild = query(idx * 2, start, mid, left, right, mode)
    rightChild = query(idx * 2 + 1, mid + 1, end, left, right, mode)
    if mode == 0 : return max(leftChild, rightChild)
    else : return min(leftChild, rightChild)

n, m = map(int, sys.stdin.readline().split())
data = [int(sys.stdin.readline()) for _ in range(n)]
segTree = [(0, sys.maxsize)] * (4 * n)
build(1, 1, n)
for _ in range(m) :
    a, b = map(int, sys.stdin.readline().split())
    maxValue = query(1, 1, n, a, b, 0)
    minValue = query(1, 1, n, a, b, 1)
    print(minValue, maxValue)