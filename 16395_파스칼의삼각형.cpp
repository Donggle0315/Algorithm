#include <iostream>

using namespace std;

int main() {
    int n,k;
    int arr[31][31] = {0};

    cin >> n >> k;

/*
1
1  1
1  2  1
1  3  3  1
1  4  6  4  1
1  5 10 10  5  1
1  6 15 20 15  6  1
*/

    for (int i = 0; i < n; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }

    for (int i = 2; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
    }

    cout << arr[n-1][k-1] << "\n";

    return 0;
}