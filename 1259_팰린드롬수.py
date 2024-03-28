import sys

while(True) :
    num = sys.stdin.readline().rstrip()
    if num == '0' : break
    if(num[::-1] == num) : print("yes")
    else : print("no")