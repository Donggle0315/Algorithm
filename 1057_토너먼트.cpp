#include <iostream>

using namespace std;

int getRound(int,int,int);

int main() {
    int n, p1, p2;
    cin >> n >> p1 >> p2;

    cout << getRound(n, p1, p2) << "\n";

    return 0;
}

int getRound(int n, int p1, int p2) {
    int round = 0;
    while (p1 != p2) {
        p1 = (p1 + 1) / 2;
        p2 = (p2 + 1) / 2;
        round++;
    }

    return round;
}

