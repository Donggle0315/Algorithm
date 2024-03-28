#include <iostream>
#include <vector>

using namespace std;

vector<int> getLIS(vector<int>);

int main() {
    int arrLength;
    vector<int> arr;
    vector<int> ans;

    cin >> arrLength;
    for (int i = 0; i < arrLength; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    ans = getLIS(arr);

    cout << ans.size() << "\n";
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans.at(i) << " ";
    }
    cout << "\n";

    return 0;
}

vector<int> getLIS(vector<int> arr) {
    vector<int> ans;
    int arrLength = arr.size();
    int maxIdx = 0;
    int *dp = new int[arrLength];

    dp[0] = 1;

    for (int i = 0; i < arrLength; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr.at(i) > arr.at(j) && dp[j] + 1 >= dp[i]) {
                dp[i] = dp[j] + 1;
            }
            if (dp[i] > dp[maxIdx]) maxIdx = i;
        }
    }

    int size = dp[maxIdx];
    int value = arr.at(maxIdx) + 1;
    for (int i = maxIdx; i >= 0; i--) {
        if (dp[i] == size && arr.at(i) < value) {
            ans.push_back(arr.at(i));
            size--;
            value = arr.at(i);
        }
    }    


    return ans;
}