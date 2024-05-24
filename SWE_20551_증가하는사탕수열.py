tc = int(input())

for case in range(tc) :
    data = list(map(int, input().split()))
    cnt = 0
    while (data[2] <= data[1]) :
        cnt += 1
        data[1] -= 1
    while (data[1] <= data[0]) :
        cnt += 1
        data[0] -= 1
    
    if data[0] < 1 or data[1] < 1 or data[2] < 1 :
        print("#%d %d"%(case + 1, -1))
    else :
        print("#%d %d"%(case + 1, cnt))