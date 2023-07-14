#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Plus(int, int);
//덧셈 
int Minus(int, int);
//뺄셈
int Multiply(int, int);
//곱셈
int Div(int, int);
//나눗셈
void init();
//동적 할당 및 입력
void finish();
//동적 해제
void backtracking(int);
//백트레킹을 이용하여 연산
void isMaxMin();
//연산 최종 결과 중 최대 최솟값인지 확인

int n;//숫자의 개수
int* num;//숫자 입력
int* res;//연산 결과
int oper[4] = { 0 };//연산자 개수
int min, max;//최대, 최소값

int main() {
	init();
	backtracking(0);
	printf("%d\n%d", max, min);
	finish();

	return 0;
}

void isMaxMin() {
	if (res[n - 1] > max) {
		max = res[n - 1];
	}
	if (res[n - 1] < min) {
		min = res[n - 1];
	}
}

void backtracking(int depth) {
	int i;
	if (depth == n-1) {//연산을 다함
		isMaxMin();//최대 최소 조사
		return;
	}
	for (i = 0; i < 4; i++) {//모든 연산자에 대해
		if (oper[i] == 0) {//남아있는 연산자가 없으면
			continue;
		}
		oper[i]--;//해당 연산자 사용
		switch (i) {
			case 0://덧셈
				res[depth + 1] = Plus(res[depth], num[depth + 1]);//이전 연산 결과와 현재 수를 연산하여 연산결과에 저장
				backtracking(depth + 1);//다음 연산
				break;
			case 1://뺄셈
				res[depth + 1] = Minus(res[depth], num[depth + 1]);//이전 연산 결과와 현재 수를 연산하여 연산결과에 저장
				backtracking(depth + 1);//다음 연산
				break;
			case 2://곱셈
				res[depth + 1] = Multiply(res[depth], num[depth + 1]);//이전 연산 결과와 현재 수를 연산하여 연산결과에 저장
				backtracking(depth + 1);//다음 연산
				break;
			case 3://나눗셈
				res[depth + 1] = Div(res[depth], num[depth + 1]);//이전 연산 결과와 현재 수를 연산하여 연산결과에 저장
				backtracking(depth + 1);//다음 연산
				break;
		}
		oper[i]++;//해당 연산자 사용 완료
	}
}

void init() {
	int i;
	scanf("%d", &n);
	num = (int*)malloc(n * sizeof(int));
	res = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	res[0] = num[0];
	min = 1000000001;
	max = -1000000001;
}

void finish() {
	free(num);
}


int Plus(int a, int b) {
	return a + b;
}

int Minus(int a, int b) {
	return a - b;
}

int Multiply(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	if (a < 0) {
		return -(a * (-1) / b);
	}
	return a / b;
}
