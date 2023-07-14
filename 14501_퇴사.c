#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void init();
//입력
int makeSchedule();
//최대 이득을 계산하고 최대 이득값 반환

int list[16][2] = { 0 };//걸리는 날과 값을 저장
int dp[16] = { 0 };//i번째 날부터 일했을 떄 최대로 벌 수 있는 돈 저장
int n;

int main() {
	init();
	printf("%d", makeSchedule());

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &list[i][0], &list[i][1]);
	}
}

int makeSchedule() {
	int i;
	dp[n] = 0;
	for (i = n - 1; i >= 0; i--) {//마지막날 부터
		if (i + list[i][0] > n) {//회사에 없을 때라 상담 불가
			dp[i] = dp[i+1];//다음날과 같음
		}
		else {//끝나는 날까지도 회사에는 있음
			if (dp[i+1]-dp[i+list[i][0]] < list[i][1]) {//이날 일을 하는게 이득
				dp[i] = list[i][1] + dp[i + list[i][0]];//현재하는 일의 값 + 현재 일을 끝나고 난 뒤 값
			}
			else {
				dp[i] = dp[i + 1];//다음날과 같음
			}
		}
	}
	return dp[0];

}