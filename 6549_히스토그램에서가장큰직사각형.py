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
    if right < start or end < start : return INF
    if start <= left and right <= end : return segTree[idx]
    
    mid = (start + end) // 2
    leftChild = query(idx * 2, start, mid, left, right)
    rightChild = query(idx * 2 + 1, mid + 1, end, left, right)
    return min(leftChild, rightChild)

while True :
    data = list(map(int, sys.stdin.readline().split()))
    if data[0] == 0 : break
    
    n = data[0]
    data = data[1:]
    segTree = [INF] * (4 * n)
    build(1,1,n)