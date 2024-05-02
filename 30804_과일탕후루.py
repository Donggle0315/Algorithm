import sys

n = int(sys.stdin.readline())
fruit = sys.stdin.readline().split()

dic = dict()
for ele in set(fruit) :
    dic[ele] = 0
    
start = 0
end = 0
fruitCnt = 0
ans = 0
while True :
    if fruitCnt <= 2 and start < n:
        dic[fruit[start]] = dic[fruit[start]] + 1
        if dic[fruit[start]] == 1 :
            fruitCnt += 1
        start += 1
    elif fruitCnt > 2 and start < n:
        dic[fruit[end]] = dic[fruit[end]] - 1
        if dic[fruit[end]] == 0 :
            fruitCnt -= 1
        end += 1
    else :
        break
    if fruitCnt <= 2 :
        ans = max(ans, start - end)
        
print(ans)