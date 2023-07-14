#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력 및 동적 할당
void finish();
//동적 해제
void printResult();
//m개 만큼 채워지면 저장된 숫자 출력
void findPermutation(int);
//재귀를 통한 백트레킹으로 순열을 채움

int* result;//출력할 값 저장
int* visited;//방문 여부 저장
int n, m;

int main() {

	init();
	findPermutation(0);
	finish();


	return 0;
}

void init() {
	scanf("%d %d", &n, &m);
	result = (int*)malloc(m * sizeof(int));
	visited = (int*)calloc(n + 1, sizeof(int));
}

void finish() {
	free(result);
	free(visited);
}

void printResult() {
	int i;
	for (i = 0; i < m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

void findPermutation(int depth) {
	int i;
	if (depth == m) {//다 채워졌을 경우
		printResult();
		return;
	}
	for (i = 1; i <= n; i++) {//1부터 n까지의 수 중
		if (visited[i] == 0) {//방문하지 않았다면
			visited[i] = 1;//방문하고
			result[depth] = i;//저장하고
			findPermutation(depth + 1);//다음 순서로 재귀
			visited[i] = 0;//방문이 끝남
		}
	}
}