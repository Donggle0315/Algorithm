## 스택 & 큐 & 덱

#- 리스트 혹은 덱으로 구현 가능함
#- 덱(Dequeue)
    
from collections import deque

d1 = deque('abc') # {'a','b','c'}
d2 = deque([1,2,3]) # {1, 2, 3}
d3 = deque() # { }

d1.append('d') # add to right side
d1.appendleft('e') # add to left side

k1 = d1.pop() # return and remove the rightmost item
k2 = d1.popleft() # return and remove the leftmost item

r1 = d1.reverse() # reverse the deque
    
    
#- 스택 → append(), pop()
#- 큐 → append(), popleft()
    

## 이분 탐색

#- binary search 구현
#- O(logN)
    
import bisect

data = [1, 2, 3, 4, 5]
target = 3

idx = bisect.bisect_left(data, target)
# idx = 2 return

#정렬된 리스트에서 특정 값의 개수
cnt = bisect.bisect_right(data, target) - bisect.bisect_left(data, target)    

## 조합 & 순열

#- 순열(Permutation) : 서로 다른 n개 중 r 개를 골라 순서를 정해 나열하는 가짓수
    
import itertools

arr = [1, 2, 3]
permu = list(itertools.permutations(arr, 2))

#[(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)]
    
#- 조합(Combination) : 서로 다른 n개 중 r 개를 골라 순서에 상관없이 나열하는 가짓수
    
import itertools

arr = [1, 2, 3]
permu = list(itertools.combinations(arr, 2))

#[(1, 2), (1, 3), (2, 3)]
    

## DFS & BFS

#- Init
    
# make edges
edges = [[] for _ in range(vertex_cnt+1)]
for i in range(edge_cnt) :
    e1, e2 = map(int, sys.stdin.readline().split())
    edges[e1].append(e2)
    edges[e2].append(e1)

# make visited
visited = [False] * (vertex_cnt + 1)
    
#- DFS
    
def dfs(edges, visited, vertex) :
    visited[vertex] = True
    print(vertex, end = ' ')
    
    for next in edges[vertex] :
        if not visited[next] :
            dfs(edges, visited, next)
    
#- BFS
    
    from collections import deque
    
    def bfs(edges, visited, vertex) :
        queue = deque([vertex])
        visited[vertex] = True
        
        while queue :
            now = queue.popleft()
            print(now, end = ' ')
            for next in edges[now] :
                if not visited[next] :
                    queue.append(next)
                    visited[next] = True
    

## Dijkstra

#- 하나의 정점에서 나머지 모든 정점까지의 최단 거리 찾기
#- Init
    
import sys

INF = sys.maxsize

vertexCnt, edgeCnt = map(int, sys.stdin.readline().split())
startVertex = int(sys.stdin.readline())

edges = [[] for _ in range(vertexCnt+1)]
for _ in range(edgeCnt) :
    e1, e2, weight = map(int, sys.stdin.readline().split())
    edges[e1].append((weight, e2)) #가중치, 도착지 순서로 삽입
distance = [INF] * (v+1) #최초 거리를 INF로 초기화

dijkstra(edges, distance, k)
    
#- Dijkstra
    
import heapq

def dijkstra(edges, distance, start) :
    distance[start] = 0
    heap = []
    heapq.heappush(heap, (0, start)) #최소힙으로 (가중치, 노드)로 시작지점 저장
    
    while heap : # 힙에 원소가 존재하는 동안
        weight, now = heapq.heappop(heap) #가중치가 가장 적은 노드를 꺼냄
        if distance[now] < weight : continue #이미 최소일 경우
        for w, next in edges[now] : #현재 노드에서 이동할 수 있는 노드들 조사
            nextWeight = w + weight
            if nextWeight < distance[next] : #적은 가중치로 이동 가능 -> 갱신 및 삽입
                distance[next] = nextWeight
                heapq.heappush(heap, (nextWeight, next))
        

## Floyd-Warshall

#- 모든 정점 사이의 최단 경로를 찾는 알고리즘
#- 알고리즘
#    - 하나의 정점에서 다른 정점으로 바로 갈 수 있으면 최소 비용을, 갈 수 없다면 INF를 배열에 저장
#    - 3중 반복문을 통해 거쳐가는 정점을 설정한 후, 해당 정점을 거쳐가서 비용이 줄어드는 경우 값을 변경
#    - 반복하여 모든 정점 사이의 최단 경로를 탐색
#- 코드
    
    #initialize
graph = [[INF] * (n + 1) for _ in range(n + 1)]

for _ in range(m) :
    e1, e2, w = map(int, sys.stdin.readline().split())
    graph[e1][e2] = min(graph[e1][e2], w) #더 적은 비용으로
for i in range(1, n + 1) : #제자리는 0
    graph[i][i] = 0
    
#플로이드 워셜
def floydWarshall(distance) : 
    for k in range(1, n + 1) :
        for i in range(1, n + 1) :
            for j in range(1, n + 1) :
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
    

## 특정 크기의 2차원 배열을 초기화할 때에는 리스트 컴프리헨션을 사용

#- 잘못된 방법
    
# N * M 크기의 2차원 리스트 초기화(잘못된 방법)
n = 3
m = 4
array = [[0] * m] * n # [[0,0,0,0],[0,0,0,0], [0,0,0,0]]

array[1][1] = 5 # [[0,5,0,0],[0,5,0,0],[0,5,0,0]]

# 내부적으로 3개의 리스트가 모두 동일한 객체에 대한 3개의 레퍼런스로 인식되기 때문
    
#- 올바른 방법
    
# N * M 크기의 2차원 리스트 초기화
n = 3
m = 4

array = [[0] * m for _ in range(n) ] # [[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    

## 에라토스테네스의 체

# - 소수 판별 알고리즘
# - 시간 복잡도

# O(\sqrt{N})

# - 알고리즘
#     - 2부터 구하고자 하는 구간의 모든 수를 나열
#     - 자기 자신을 제외한 소수의 배수를 모두 지움
#     - 구하고자하는 최대값의 제곱수까지만 연산하면 됨
# - 코드
    
def getPrimes(last) : #최대값 + 1을 인자로
    data = [True] * last #True는 소수, False는 합성수
    data[0] = data[1] = False #0,1은 소수 X
    for i in range(2, int(math.sqrt(last)) + 1) : #제곱근까지만
        if data[i] == False : continue #이미 소수의 배수였을 경우
        for j in range(2*i, last, i) : #자기 자신을 제외한 배수에 대해
            data[j] = False

    primes = [] #소수 값을 직접 담음
    for i in range(last) :
        if data[i] : primes.append(i)
    return primes
