import sys

tc = int(sys.stdin.readline())

for _ in range(tc) :
    year = sys.stdin.readline()
    div = int(year[2:])
    year = int(year) + 1
    if year % div :
        print("Bye")
    else :
        print("Good")
    