#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//동적 할당 및 입력
void finish();
//동적 해제
void backtracking(int,int);
//백트레킹을 이용해 부분수열을 구성, 부분수열의 합이 s인 경우 count++
int sum(int);
//부분 수열의 합을 구해 반환

int n, s;//n은 숫자의 개수, s는 구하고자 하는 부분 수열의 합
int* list;//수열
int* bt;//선택된 부분 수열
int count;//s를 만족하는 부분수열의 개수



int main() {
	init();
	backtracking(-1,0);
	printf("%d", count);
	finish();


	return 0;
}

void backtracking(int start, int depth) {
	int i;
	if (depth == n) {//모든 원소를 탐색했다면
		return;
	}
	for (i = start + 1; i < n; i++) {//결정되지 않은 원소에 대해
		bt[depth] = list[i];//부분수열에 포함
		if (sum(depth+1) == s) {//부분수열의 합이 s와 같다면
			count++;
		}
		backtracking(i, depth + 1);//다음 원소를 고름
	}
}

int sum(int d) {
	int i, sum = 0;
	for (i = 0; i < d; i++) {
		sum += bt[i];
	}
	return sum;
}


void init() {
	int i;
	scanf("%d %d", &n, &s);
	list = (int*)malloc(n * sizeof(int));
	bt = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	count = 0;
}

void finish() {
	free(list);
	free(bt);
}