#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>

using namespace std;

int getMaxScore();
int getScore(string);
bool isOut(int,int);
int hitting(int,int,int[]);

int inning;
vector<vector<int> > expect_result;

int main() {
    cin >> inning;
    for(int i = 0; i < inning; i ++) {
        vector<int> inning_result;
        for(int player = 0; player < 9; player++) {
            int tmp;
            cin >> tmp;
            inning_result.push_back(tmp);
        }
        expect_result.push_back(inning_result);
    }

    cout << getMaxScore() << "\n";

    return 0;
}

int getMaxScore() {
    string order = "123456789";
    int max = 0;
    sort(order.begin(), order.end());
    do {
        if(order.at(3) == '1') {
            int score = getScore(order);
            max = max > score ? max : score;
        }
    } while(next_permutation(order.begin(), order.end()));

    return max;
}

int getScore(string order) {
    int score = 0;
    int batter = 0;
    
    for (int inning_idx = 0; inning_idx < inning; inning_idx++) {
        int outCnt = 0;
        int basement[] = {0,0,0};
        while (outCnt < 3) {
            //cout << "in loop : " << inning_idx << ", " << outCnt <<"\n";
            if (isOut(inning_idx, order[batter] - '0')) outCnt++;
            else score += hitting(inning_idx, order[batter] - '0', basement);
            // cout << "batter : " << order[batter] - '0' << " hit " << expect_result.at(inning_idx).at((order[batter] - '0') - 1) << "\n";
            
            batter = (batter + 1) % 9;
        }
        // cout << "inning change\n";
    }
    // cout << order << " : " << score << "\n";
    return score;
}

bool isOut(int inning_idx, int batter) {
    return (expect_result.at(inning_idx).at(batter-1) == 0) ? true : false;
}

int hitting(int inning_idx, int batter, int basement[]) {
    int score = 0;
    int hit = expect_result.at(inning_idx).at(batter-1);
    if (hit == 1) {
        score = basement[2];
        basement[2] = basement[1];
        basement[1] = basement[0];
        basement[0] = 1;
    } else if (hit == 2) {
        score = basement[2] + basement[1];
        basement[2] = basement[0];
        basement[1] = 1;
        basement[0] = 0;
    } else if (hit == 3) {
        score = basement[2] + basement[1] + basement[0];
        basement[2] = 1;
        basement[1] = basement[0] = 0;
    } else if (hit == 4) {
        score = basement[2] + basement[1] + basement[0] + 1;
        basement[2] = basement[1] = basement[0] = 0;
    }

    return score;
}