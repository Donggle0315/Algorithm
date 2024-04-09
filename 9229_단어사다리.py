import sys

def solve() :
    for i in range(len(data) - 1) :
        a = data[i]
        b = data[i + 1]
        diff = 0
        if len(a) != len(b) :
            print("Incorrect")
            return
        
        for k in range(len(a)):
            if a[k] != b[k] : diff += 1
        if diff != 1 :
            print("Incorrect")
            return
    print("Correct")
                            
        
data = []
while True :
    line = sys.stdin.readline().strip()
    if line == "#" : 
        if len(data) == 0 : break
        solve()
        data = []
    else :
        data.append(line)
    