tc = int(input())

for case in range(tc) :
    n, k = map(int, input().split())
    data = list(map(int, input().split()))
    
    data.sort()
    ans = 1_000_000_000
    for idx in range(0, n - k + 1) :
        ans = min(ans, data[idx + k - 1] - data[idx])
        
    print("#%d %d"%(case + 1, ans))