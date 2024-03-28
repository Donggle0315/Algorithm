#include <iostream>
#include <vector>

using namespace std;

int chu_count, ball_count;
int max_weight;
int* chu_weight;
int* ball_weight;
int chu_sum;
vector<char> ans;
bool dp[31][2*30*500] = {false,};


void solve() {
    dp[0][chu_sum] = true;

    for (int i = 0; i < chu_count; i++) {
        int chu = chu_weight[i];
        
        for (int j = 0; j <= 2 * chu_sum; j++) {
            if (dp[i][j] == false) continue;
            dp[i+1][j] = true;
            if (j - chu >= 0) dp[i+1][j-chu] = true;
            if (j + chu <= 2 * chu_sum) dp[i+1][j+chu] = true; 
        }
        
    }
    
    for (int i = 0; i < ball_count; i++) {
        if (dp[chu_count][chu_sum + ball_weight[i]] == true) ans.push_back('Y');
        else ans.push_back('N');
    }

}

void inputLogic() {
    max_weight = 0;
    chu_sum = 0;

    cin >> chu_count;
    chu_weight = new int[chu_count];

    for (int i = 0; i < chu_count; i++) {
        cin >> chu_weight[i];
        chu_sum += chu_weight[i];
    }
    cin >> ball_count;
    ball_weight = new int[ball_count];

    for (int i = 0; i < ball_count; i++) {
        cin >> ball_weight[i];
        if (max_weight < ball_weight[i]) {
            max_weight = ball_weight[i];
        }
    }
}

void outputLogic() {
    for(int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    cout << "\n";
}

int main() {
    inputLogic();
    solve();
    outputLogic();
    
    delete[] chu_weight;
    delete[] ball_weight;

    return 0;
}

