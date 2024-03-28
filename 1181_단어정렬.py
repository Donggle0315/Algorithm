import sys

wordCnt = int(sys.stdin.readline())
words = [sys.stdin.readline().rstrip() for i in range(wordCnt)]

wordsTmp = [(len(i), i) for i in set(words)]
wordsTmp.sort()

result = [i[1] for i in wordsTmp]
for word in result :
    print(word)