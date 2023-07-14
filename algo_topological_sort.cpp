/*위상정렬 topological sort
concept : 순서가 정해져있는 작업을 차례로 수행해야 할 때, 그 순서를 결정해주는 알고리즘
implement to DAG(directed Actclic Graph) : 방향이 있고 사이클이 없는 그래프에만 적용가능
두가지 해결책 
1. 특정한 그래프로 위상정렬이 가능한가
2. 위상정렬이 가능하다면 그 결과가 무엇인지

구현 방법 : queue를 사용함
진입차수 : 해당 노드로 들어오는 간선의 개수

1. 진입차수가 0인 정점에 큐에 삽입
2. 큐에서 원소를 꺼내 연결된 모든 간선 제거
3. 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입
4. 큐가 빌 때까지 2~3번 과정 반복. 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재하는 것이고, 모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n;//number of nodes 
int m;//number of edges
int inDegree[MAX];//nodes' 진입차수
vector<int> a[MAX];//각 정점에 연결되어 있는 모든 노드의 정보

void topologySort(){
    int result[MAX];
    queue<int> q;
    //진입차수가 0인 노드를 큐에 삽입
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0) q.push(i);
    }
    //위상정렬이 완전히 수행되려면 정확히 N개의 노드를 방문해야함
    for(int i=1;i<=n;i++){
        //n개를 방문하기 전에 큐가 빈다면 사이클이 발생했음
        if(q.empty()){
            cout<<"cycle occurs\n";
            return;
        }
        int x=q.front();
        q.pop();
        result[i]=x;
        for(int j=0;j<a[x].size();j++){
            int y=a[x][j];
            //새롭게 진입차수가 0이 된 정점을 큐에 삽입
            if(--inDegree[y]==0) q.push(y);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n";
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s,e;
        cin>>s>>e;
        a[s].push_back(e);
        inDegree[e]++;
    }
}