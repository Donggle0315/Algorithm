#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void HanoiTowerCount(int, int, int, int);//하노이 타워 이동 횟수를 세는 함수
void HanoiTower(int, int, int, int);//하노이 타워 이동 경로를 출력하는 함수

int count = 0;

int main() {

	int num;//원판의 개수
	scanf("%d", &num);
	HanoiTowerCount(num,1,2,3);//하노이 타워 이동 횟수를 세서 count변수에 저장
	printf("%d\n", count);
	HanoiTower(num, 1, 2, 3);//하노이 타워 이동 경로를 출력

	return 0;
}

void HanoiTowerCount(int num, int from, int by, int to) {
	if (num == 1) {
		count++;//옮기는 횟수
	}
	else {
		HanoiTowerCount(num - 1, from, to, by);
		count++;//옮기는 횟수
		HanoiTowerCount(num - 1, by, from, to);
	}
}

void HanoiTower(int num, int from, int by, int to) {
	if (num == 1) {//이동할 원판의 개수가 1개일 때
		printf("%d %d\n", from, to);//from에서 to까지만 원판 1개만 이동하는건 from->to로 바로 옮기면 되므로 count++
	}
	else {
		HanoiTower(num - 1, from, to, by);//원판 n개 중 작은 원판 n-1개를 from에서 by로 옮기는 과정
		printf("%d %d\n", from, to);//큰 원판 1개를 from에서 to로 옮기는 과정은 한번이면 됨.
		HanoiTower(num - 1, by, from, to);//by에 존재했던 원판 n-1개를 to로 옮기는 과정
	}
}