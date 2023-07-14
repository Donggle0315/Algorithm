#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void init();
int findNext(int);
int isHere(int);
int cntMinPlug();
int findLast();

int n,k,emptyPlug;
vector<int> items;
int* plug;
int* nextPlug;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<cntMinPlug()<<"\n";
    
    return 0;
}

void init(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        items.push_back(tmp);
    }
    plug=new int[n];
    nextPlug=new int[n];
    for(int i=0;i<n;i++){
        plug[i]=0;
        nextPlug[i]=-1;
    }
    emptyPlug=n;
}

int cntMinPlug(){
    int cnt=0;
    for(int i=0;i<k;i++){
        int tmp=isHere(i);//이미 꽂혀있으면 해당 플러그 인덱스, 아니면 -1반환
        if(tmp!=-1){
            nextPlug[tmp]=findNext(i);//그대로 가고, 다음 숫자 저장
        }
        else if(emptyPlug!=0){
            plug[n-emptyPlug]=items[i];
            nextPlug[n-emptyPlug]=findNext(i);
            emptyPlug--;
        }
        else{
            int q=findLast();//마지막으로 나오는 거 인덱스 구하고
            plug[q]=items[i];//해당 인덱스 플러그 빼고 꽂고
            cnt++;//개수 ++
            nextPlug[q]=findNext(i);//꽂은거의 다음 숫자 저장
        }
    }
    return cnt;
}

int isHere(int idx){
    for(int i=0;i<n;i++){
        if(plug[i]==items[idx]) return i;
    }
    return -1;
}

int findNext(int iidx){
    for(int i=iidx+1;i<k;i++){
        if(items[i]==items[iidx]){
            return i;
        }
    }
    return -1;
}

int findLast(){
    int idx=0;
    for(int i=0;i<n;i++){
        if(nextPlug[i]==-1){
            return i;
        }
        if(nextPlug[i]>nextPlug[idx]){
            idx=i;
        }
    }
    return idx;
}