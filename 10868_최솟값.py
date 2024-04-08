import sys

INF = sys.maxsize

def build(idx, start, end) :
    if start == end :
        segTree[idx] = data[start - 1]
        return
    mid = (start + end) // 2
    build(idx * 2, start, mid)
    build(idx * 2 + 1, mid + 1, end)
    segTree[idx] = min(segTree[idx * 2], segTree[idx * 2 + 1])
    
def query(idx, start, end, left, right) :
    if right < start or end < left :
        return INF
    if left <= start and end <= right :
        return segTree[idx]
    mid = (start + end) // 2
    leftChild = query(idx * 2, start, mid, left, right)
    rightChild = query(idx * 2 + 1, mid + 1, end, left, right)
    return min(leftChild, rightChild)

n, m = map(int, sys.stdin.readline().split())
data = [int(sys.stdin.readline()) for _ in range(n)]
segTree = [INF] * (4 * n)

build(1, 1, n)
for _ in range(m) :
    a, b = map(int, sys.stdin.readline().split())
    print(query(1, 1, n, a, b))