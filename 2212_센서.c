#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init();
//동적 배열 할당 및 입력
void finish();
//동적 해제
void qsorting(int*,int, int);
//입력으로 들어온 배열 오름차순 정렬
void findDistance();
//센서간 거리를 측정하여 절대값을 dist 배열에 저장
int findMinSum();
//가장 긴 거리를 집중국-1개 만큼 뺸 뒤, 거리의 합 반환

int n, k;
int* list;
int* dist;



int main() {
	init();
	qsorting(list,0, n - 1);
	findDistance();
	qsorting(dist, 0, n - 2);

	printf("%d", findMinSum());
	finish();

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	scanf("%d",&k);
	list = (int*)malloc(n * sizeof(int));
	dist = (int*)malloc((n-1) * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
}

void qsorting(int* arr, int left, int right) {
	int pl = left;
	int pr = right;
	int x = arr[(left + right) / 2];
	int tmp;
	do {
		while (arr[pl] < x) {
			pl++;
		}
		while (arr[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			tmp = arr[pl];
			arr[pl] = arr[pr];
			arr[pr] = tmp;
			pr--;
			pl++;
		}
	} while (pl <= pr);
	if (pl < right) {
		qsorting(arr,pl, right);
	}
	if (left < pr) {
		qsorting(arr,left, pr);
	}
}

void findDistance() {
	int i;
	for (i = 0; i < n - 1; i++) {
		dist[i] = abs(list[i] - list[i + 1]);//센서 사이의 거리의 절댓값
	}
}

int findMinSum() {
	int i, sum = 0;
	if (n == k) {
		return 0;//센서 수와 집중국 수가 같으면 센세 위치에 집중국을 놓으면 됨
	}
	for (i = 0; i < n-k; i++) {//낮은 수부터 센서-(집중국-1)의 합 
		sum += dist[i];
	}
	return sum;
}

void finish() {
	free(list);
	free(dist);
}