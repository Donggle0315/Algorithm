tc = int(input())

for case in range(tc) :
    n = int(input())
    data = list(map(int, input().split()))
    data.sort(reverse=True)
    visited = [False] * n * 2
    ans = []

    for idx in range(2 * n) : 
        if visited[idx] == True :
            continue
        for point in range(idx + 1, 2 * n) :
            if data[idx] * 3 // 4 == data[point] and visited[point] == False:
                ans.append(data[point])
                visited[point] = True  
                break  
    ans.sort()
    for i in range(len(ans)) :
        ans[i] = str(ans[i])
    
    print("#%d %s"%(case + 1,' '.join(ans)))
    
    