import sys
sys.setrecursionlimit(10 ** 6)
def biSearchLength(data, target, left, right) :
    if left >= right : return -1
    count = 0
    middle = (left + right) // 2
    for i in data :
        count += (i // middle)
    
    if count > target : return biSearchLength(data, n, middle + 1, right)
    elif count < target : return biSearchLength(data, n, left, middle)
    return middle

def getMaxLength(data, target, maxValue) :
    while True :
        count = 0
        for i in data :
            count += (i // maxValue)
        if count == target : maxValue += 1
        else : break
    return maxValue - 1
    

data = list(map(int, sys.stdin.readline().split()))
k = data[0]; n = data[1]
data = [int(sys.stdin.readline()) for i in range(k)]

maxLength = biSearchLength(data, n, 0, max(data) + 1)
maxLength = getMaxLength(data, n, maxLength)
print(maxLength)
