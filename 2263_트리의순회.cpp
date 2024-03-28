#include <iostream>

using namespace std;

void getPreOrder(int,int,int,int);

int nodeCnt;
int *inOrder;
int *postOrder;
int *inIndex;

int main() {
    cin >> nodeCnt;

    postOrder = new int[nodeCnt];
    inIndex = new int[nodeCnt+1];

    for(int i = 0; i < nodeCnt; i++) {
        int num;
        cin >> num;
        inIndex[num] = i;
    }
    for(int i = 0; i < nodeCnt; i++) {
        cin >> postOrder[i];
    }
    

    getPreOrder(0, nodeCnt-1, 0, nodeCnt-1);

    delete[] postOrder;
    delete[] inIndex;

    return 0;
}

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postOrder[postEnd];
    int rootIdx = inIndex[root];
    int left = rootIdx - inStart;
    int right = inEnd - rootIdx;

    cout << root << " ";

    getPreOrder(inStart, rootIdx-1, postStart, postStart + left - 1);
    getPreOrder(rootIdx + 1, inEnd, postStart + left, postEnd -1); 
}