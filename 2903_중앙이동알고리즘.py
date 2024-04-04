# 0=4 / 1=9 / 2=25

n = int(input())
dot = 2

for i in range(n) :
    dot = dot + (dot - 1)
print(dot**2)