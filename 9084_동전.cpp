#include <iostream>
#include <cstring>
using namespace std;

long long coinDP(int* coin, int goalMoney, int n);
void solve();

int main() {
    //N원을 포함해서 만들 수 있는 경우 + N원을 포함하지 않고 만드는 경우
    int tc;
    cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}

void solve() {
    int n;
    int* money;
    int goalMoney;

    cin >> n;
    money = new int[n];
    for(int i = 0; i < n ;i++) {
        cin >> money[i];
    }
    cin >> goalMoney;

    cout << coinDP(money, goalMoney, n) << "\n";
    delete[] money;
}

long long coinDP(int* coin, int goalMoney, int n) {
    long long* dp = new long long[goalMoney+1];
    memset(dp, 0, sizeof(long long) * (goalMoney + 1));

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= goalMoney; j++) {
            dp[j] = dp[j] + dp[j-coin[i]];
        }
    }

    long long ans = dp[goalMoney];
    delete[] dp;

    return ans;
}