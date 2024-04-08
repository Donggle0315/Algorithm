import sys

DIV = 1000000007

def build(idx, start, end) :
    if start == end :
        segTree[idx] = data[start - 1]
        return
    mid = (start + end) // 2
    build(idx * 2, start, mid)
    build(idx * 2 + 1, mid + 1, end)
    segTree[idx] = (segTree[idx * 2] * segTree[idx * 2 + 1]) % DIV
    
def query(idx, start, end, left, right) :
    if right < start or end < left :
        return 1
    if left <= start and end <= right :
        return segTree[idx]
    mid = (start + end) // 2
    leftChild = query(idx * 2, start, mid, left, right)
    rightChild = query(idx * 2 + 1, mid + 1, end, left, right)
    return (leftChild * rightChild) % DIV

def update(idx, start, end, after, updateIdx) :
    if start > updateIdx or end < updateIdx : return
    
    if start == end : 
        segTree[idx] = after
        return
    
    mid = (start + end) // 2
    update(idx * 2, start, mid, after, updateIdx)
    update(idx * 2 + 1, mid + 1, end, after, updateIdx)
    segTree[idx] = (segTree[idx * 2] * segTree[idx * 2 + 1]) % DIV
    
n, m, k = map(int, sys.stdin.readline().split())
data = [int(sys.stdin.readline()) for _ in range(n)]
segTree = [1] * (4 * n)
build(1,1,n)
for _ in range(m + k) :
    a, b, c = map(int, sys.stdin.readline().split())
    if a == 1 :
        update(1,1,n, c, b)
    else :
        print(query(1, 1, n, b, c))