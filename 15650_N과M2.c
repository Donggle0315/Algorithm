#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//동적 할당 및 입력
void finish();
//동적 해제
void printResult();
//다 채워지면 출력
void findCombination(int);
//오름차순으로 중복 없이 숫자를 채워넣음

int* result;//출력할 결과 값 저장
int* visited;//방문 여부
int n, m;

int main() {

	init();
	findCombination(1);
	finish();


	return 0;
}

void init() {
	scanf("%d %d", &n, &m);
	result = (int*)malloc((m + 1) * sizeof(int));
	visited = (int*)calloc(n + 1, sizeof(int));
	result[0] = 0;
}

void finish() {
	free(result);
	free(visited);
}

void printResult() {
	int i;
	for (i = 1; i <= m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

void findCombination(int depth) {
	int i;
	if (depth == m + 1) {//다 채워지면
		printResult();//출력
		return;
	}
	for (i = result[depth - 1] + 1; i <= n; i++) {//이전 수 다음 수부터(오름차순을 위해)
		if (visited[i] == 0) {//방문 안했다면
			visited[i] = 1;//방문
			result[depth] = i;//저장
			findCombination(depth + 1);//다음 수 조사
			visited[i] = 0;//방문 끝
		}
	}
}