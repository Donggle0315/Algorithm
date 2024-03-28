import sys

def palindrome(string, front, back, flag) :
    while front < back :
        if string[front] != string[back] :
            break
        front += 1
        back -= 1
    if front >= back and flag :
        return 0
    elif front >= back and not flag :
        return 1
    elif front < back and flag :
        if palindrome(string, front + 1, back, False) == 1 or palindrome(string, front, back - 1, False) == 1 :
            return 1
        else : return 2
    else :
        return 2


tc = int(sys.stdin.readline())

for _ in range(tc) :
    string = sys.stdin.readline()
    print(palindrome(string, 0, len(string) - 2, True))