import sys

def getNum(num) :
    if dic.get(num, False) == False :
        k = getNum(num // p) + getNum(num // q) 
        dic[num] = k
        print(num, k, num // p, num // q)
        return k
    else : return dic[num]
    

n, p ,q = map(int, sys.stdin.readline().split())
print(n,p,q)
dic = dict()
dic[0] = 1
# dic[1] = 1

print(getNum(n))