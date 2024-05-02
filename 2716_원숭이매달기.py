import sys
from collections import deque


tc = int(sys.stdin.readline())

for _ in range(tc) :
    string = sys.stdin.readline()
    st = deque()
    depth = 0
    for ele in string.strip() : 
        print(ele)
        if ele == '[' :
            depth += 1            
        else :
            st.append(depth)
            depth -= 1
    print(st)