import sys

n, m, l = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split()))
data.append(0)
data.append(l)
data.sort()


start = 1
end = l - 1
ans = 0
while start <= end :
    count = 0
    mid = (start + end) // 2
    for i in range(0, len(data) - 1):
        if data[i + 1] - data[i] > mid:
            count += (data[i + 1] - data[i] - 1) // mid
    if count > m :
        start = mid + 1
    else:
        end = mid - 1
        ans = mid
print(ans)
