import sys, math

n = int(sys.stdin.readline())
if n == 0 : 
    print(n)
else :
    rating = [int(sys.stdin.readline()) for i in range(n)]
    rating.sort()

    excludeNumber = round(n * 0.15 + 0.5)
    total = sum(rating[excludeNumber:len(rating)-excludeNumber])
    average = round(total / (n - 2 * excludeNumber) + 0.5)
    print(average)