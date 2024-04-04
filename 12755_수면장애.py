import sys

n = int(sys.stdin.readline())
#1자리 9개, 2자리 90개, 3자리 900개, 4자리 9000개, 5자리 90,000개, 6자리 900,000개, 7자리 9,000,000개, 8자리 90,000,000개 
#9          180         2700        36,000   450,000        5,400,000       63,000,000      720,000,000
#n자리 수가 차지하는 개수 9n * 10^(n-1)
cnt = [9, 180, 2700, 36000, 450000, 5400000, 63000000, 720000000]
sum = 0
idx = 0

#몇자리 수인지를 찾아냄
while sum < n :
    sum += cnt[idx]
    idx += 1

#몇번째 숫자인지 찾아냄
sum = 0
for i in range(idx - 1) :
    sum += cnt[i]
num = 10 ** (idx - 1)
while sum < n :
    sum += idx
    num += 1

#num의 idx인덱스가 n번째 숫자임
num -= 1
sum -= idx
idx = n - sum - 1
print(str(num)[idx])

