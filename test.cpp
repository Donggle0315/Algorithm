#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node{
    vector<int> child;
    int idx;
}node;

node tree[101];

int goLeaf(){//경로를 바꾸면서 리프 노드까지 도달하여 리프 노드의 번호를 반환
    int start=1;
    while(tree[start].child.size()!=0){
        int tmp=start;
        start=tree[start].child[tree[start].idx++];
        if(tree[tmp].idx == tree[tmp].child.size()){
            tree[tmp].idx=0;
        }
    }
    return start;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    vector<int> order;
    bool flag=true;
    //부모 자식 연결
    for(int i=0;i<edges.size();i++){
        tree[edges[i][0]].child.push_back(edges[i][1]);
    }
    //자식을 오름차순으로 정렬
    for(int i=0;i<101;i++){
        sort(tree[i].child.begin(),tree[i].child.end());
    }
    
    vector<int> copy_target;
    vector<int> cnt_target;
    int cnt=0;//숫자를 채워야하는 리프노드의 개수
    int insertion=0;
    for(int i=0;i<target.size();i++){
        copy_target.push_back(target[i]);
        cnt_target.push_back(0);
        if(target[i]!=0) cnt++;
    }
    cout<<"cnt :" <<cnt<<"\n";
    while(cnt){//모든 노드를 3으로 채웠을때 양수가 없게되는 순간이 최소한의 개수로 구성한 것임.
        int tmp=goLeaf();
        if(copy_target[tmp-1]>0 && copy_target[tmp-1]<=3){
            cnt--;
        }
        copy_target[tmp-1]-=3;
        cnt_target[tmp-1]++;
        order.push_back(tmp);
        insertion++;
    }
    
    for(int i=0;i<order.size();i++){
        int num=order[i];
        if(1+(cnt_target[num-1]-1)*3 >= target[num-1]){
            answer.push_back(1);
            cnt_target[num-1]--;
            target[num-1]-=1;
        }
        else if(2+(cnt_target[num-1]-1)*3 >= target[num-1]){
            answer.push_back(2);
            cnt_target[num-1]--;
            target[num-1]-=2;
        }
        else if(3+(cnt_target[num-1]-1)*3 >= target[num-1]){
            answer.push_back(3);
            cnt_target[num-1]--;
            target[num-1]-=3;
        }
        else{
            flag=false;
        }
    }
    
    for(int i=0;i<target.size();i++){
        if(target[i]!=0 || !flag){
            answer.clear();
            answer.push_back(-1);
            break;
        }
    }
    return answer;
}