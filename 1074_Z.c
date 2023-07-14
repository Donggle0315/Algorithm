#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void init();
int visiting();

int n, r, c;
int count = 0;
int main() {
	init();
	printf("%d", visiting());

	return 0;
}

void init() {
	scanf("%d %d %d", &n, &r, &c);
	n = pow(2, n);//n은 한 변의 길이
}

int visiting() {
	int p, q,sec;
	if (n == 1||(r==0&&c==0)) {//해당 위치가 찾고자 하는 곳
		return count;
	}
	else {//행렬을 4등분 한다
		p = (r / (n / 2));//0이면 위쪽, 1이면 아랫쪽
		q = (c / (n / 2));//0이면 왼쪽, 1이면 오른쪽
	}
	
	n = n/2;//4등분 했을때, 행렬 한 변의 길이
	if (p == 0) {
		if (q == 0) {//1사분면
			sec = 0;
		}
		else {//2사분면
			sec = 1;
			c -= n;
		}
	}
	else {
		if (q == 0) {//3사분면
			sec = 2;
		}
		else {//4사분면
			sec = 3;
			c -= n;
		}
		r -= n;
	}//c-=n과 r-=n은 4등분 했을 때, 해당 좌표가 위치하는 부분의 첫 원소가 (0,0)가 되도록 함
	count += sec * pow(n,2); //1,2,3,4분면을 차례로 이동하면서 이전 sec까지 이동한 횟수, 예를 들면 sec가 3이면, 1,2,3분면은 모두 이동하였으므로 3*(한 섹터의 크기)
	return visiting();//4등분 된 행렬에 대해 탐색 실시
}