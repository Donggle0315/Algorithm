tc = int(input())

for case in range(tc) :
    word = input()
    length = len(word)
    ans = True
    for idx in range(0, length) :
        if word[idx] != word[length - idx -1] :
            ans = False
            break
        
    for idx in range(0, (length - 1) // 2) :
        if word[idx] != word[(length - 1) //2 - 1 - idx] :
            ans = False
            break
        
    for idx in range((length - 1) // 2, length) :
        if word[idx] != word[length - 1 - idx] :
            ans = False
            break
    
    if ans == True :
        print("#%d YES"%(case + 1))
    else :
        print("#%d NO"%(case + 1))