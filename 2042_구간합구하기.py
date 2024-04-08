import sys

def build(idx, start, end) :
    if start == end : # leaf node
        segTree[idx] = data[start - 1]
        return
    
    mid = (start + end) // 2
    build(idx * 2, start, mid) #recurse to left
    build(idx * 2 + 1, mid + 1, end) #recurse to right
    segTree[idx] = segTree[idx * 2] + segTree[idx * 2 + 1]
    
def query(idx, start, end, left, right) :
    if right < start or end < left : #out of range
        return 0
    if left <= start and end <= right : #in range
        return segTree[idx]
    #part of range
    mid = (start + end) // 2
    leftChild = query(idx * 2, start, mid, left, right)
    rightChild = query(idx * 2 + 1, mid + 1, end, left, right)
    return leftChild + rightChild

def update(idx, start, end, value, updateIdx) :
    if start > updateIdx or end < updateIdx : return
    
    segTree[idx] += value
    
    if start == end : return
    
    mid = (start + end) // 2
    update(idx * 2, start, mid, value, updateIdx)
    update(idx * 2 + 1, mid + 1, end, value, updateIdx)
    

n, m, k = map(int, sys.stdin.readline().split())

data = [int(sys.stdin.readline()) for _ in range(n)]
segTree = [0] * (4 * n)

build(1, 1, n)
for _ in range(m + k) :
    mode, a, b = map(int, sys.stdin.readline().split())
    if mode == 1 :
        tmp = b - data[a - 1]
        data[a - 1] = b
        update(1, 1, n, tmp, a)
    else :
        print(query(1, 1, n, a, b))