tc = int(input())

for case in range(tc) :
    n, m = map(int, input().split())
    sData = input().split()
    tData = input().split()
    
    q = int(input())
    ans = ""
    for _ in range(q) :
        year = int(input())
        
        ans = ans + " " + sData[(year - 1) % n] + tData[(year - 1) % m]
    print("#%d%s"%(case + 1, ans))