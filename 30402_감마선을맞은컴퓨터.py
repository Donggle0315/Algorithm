import sys

data = []
for _ in range(15) :
    line = sys.stdin.readline().split()
    data = data + line

if 'w' in data :
    print("chunbae")
elif 'b' in data :
    print("nabi")
elif 'g' in data :
    print("yeongcheol")
