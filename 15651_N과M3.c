#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//동적 할당 및 입력
void finish();
//동적 해제
void printResult();
//다 채워지면 출력
void findSequence(int);
//중복 있게 수열을 채움

int* result;//출력할 결과 저장
int n, m;

int main() {

	init();
	findSequence(0);
	finish();


	return 0;
}

void init() {
	scanf("%d %d", &n, &m);
	result = (int*)malloc((m + 1) * sizeof(int));
}

void finish() {
	free(result);
}

void printResult() {
	int i;
	for (i = 0; i < m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

void findSequence(int depth) {
	int i;
	if (depth == m) {//다 채워지면
		printResult();//출력
		return;
	}
	for (i =1; i <= n; i++) {//중복가능하므로 visited여부 확인이 필요없음
		result[depth] = i;//저장
		findSequence(depth + 1);//다음 수 확인
	}
}