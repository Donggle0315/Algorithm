#include <iostream>

using namespace std;


void solve();
void makeTree(int[], int[], int, int, int);

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}

void solve() {
    int nodeCnt;
    cin >> nodeCnt;

    int* preTraversal = new int[nodeCnt];
    int* midTraversal = new int[nodeCnt];

    for(int i = 0; i < nodeCnt; i++) {
        cin >> preTraversal[i];
    }
    for(int i = 0; i < nodeCnt; i++) {
        cin >> midTraversal[i];
    }
    
    makeTree(preTraversal, midTraversal, 0, 0, nodeCnt);
    cout << "\n";
    delete[] preTraversal;
    delete[] midTraversal;
}

void makeTree(int preTraversal[], int midTraversal[], int root, int start, int end) {
    for (int i = start; i < end; i++) {
        if(preTraversal[root] == midTraversal[i]) {
            makeTree(preTraversal, midTraversal, root + 1, start, i);
            makeTree(preTraversal, midTraversal, root + i - start + 1, i + 1, end);
            cout << preTraversal[root] << " ";
        }
    }
}
