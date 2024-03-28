#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double probabilityPrimeGoal(double, double);
bool isPrime(int);


int main() {
    //한 팀당 최대 18골이 나올 수 있음
    double prob_a;
    double prob_b;
    cin >> prob_a >> prob_b;

    double result = probabilityPrimeGoal(prob_a/100, prob_b/100);
    cout << result << "\n";
    return 0;
}

double probabilityPrimeGoal(double prob_a, double prob_b) {
    double dp[19][19][2];
    dp[0][0][0] = 1;
    dp[0][1][0] = 0;
    dp[0][0][1] = 1;
    dp[0][1][1] = 0;


    //모든 시간에서 한 골도 넣지 못할 확률
    for (int i = 1; i <= 18; i++) {
        dp[i][0][0] = dp[i-1][0][0] * (1-prob_a);
        dp[i][0][1] = dp[i-1][0][1] * (1-prob_b);

        dp[i][i][0] = dp[i-1][i-1][0] * prob_a;
        dp[i][i][1] = dp[i-1][i-1][1] * prob_b;
    }

    for (int i = 2; i <= 18; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j][0] = dp[i-1][j][0] * (1 - prob_a) + dp[i-1][j-1][0] * prob_a;//이전 5분 점수 * 못 넣을 확률 + 이전 5분 점수-1 * 넣을 확률
            dp[i][j][1] = dp[i-1][j][1] * (1 - prob_b) + dp[i-1][j-1][1] * prob_b;
        }
    }

    double totalInter = 0;
    for(int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            if(isPrime(i) || isPrime(j)) continue;
            totalInter += dp[18][i][0] * dp[18][j][1];
        }
    }
    
    return 1 - totalInter;
}

bool isPrime(int n) {
    if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17) return true;
    return false;
}