import sys

tc = int(sys.stdin.readline())
data = [25, 10, 5, 1]
while tc != 0 :
    tc -= 1
    n = int(sys.stdin.readline())
    quarter = n // 25
    dime = n % 25 // 10
    nickel = n % 25 % 10 // 5
    penny = n % 5
    print(quarter, dime, nickel, penny)
    