#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int start;
	int end;
}node;

void init();
//동적 할당 및 입력
void sortEnd(int, int);
//끝나는 시간 기준으로 오름차순 정렬
void sortStart();
//끝나는 시간이 같을 경우, 시작 시간 기준으로 오름차순 정렬
void sorts(int, int);
//해당 범위(end값이 같은 범위)에 대해 start기준으로 정렬
int greedyCount();
//회의 최대 개수를 세고, 횟수 반환
void finish();
//동적 해제

int n;
node* list;

int main() {
	init();
	sortEnd(0, n - 1);
	sortStart();
	printf("%d", greedyCount());
	finish();

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	list = (node*)malloc(n * sizeof(node));
	for (i = 0; i < n; i++) {
		scanf("%d %d", &list[i].start, &list[i].end);
	}
}

void finish() {
	free(list);
}

void sortEnd(int left, int right) {//끝나는 시점을 기준으로 퀵정렬
	int tmps, tmpe;
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2].end;
	do {
		while (list[pl].end < x) {
			pl++;
		}
		while (list[pr].end > x) {
			pr--;
		}
		if (pl <= pr) {
			tmps = list[pr].start;
			tmpe = list[pr].end;
			list[pr].start = list[pl].start;
			list[pr].end = list[pl].end;
			list[pl].start = tmps;
			list[pl].end = tmpe;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		sortEnd(left, pr);
	}
	if (pl < right) {
		sortEnd(pl, right);
	}
}

void sortStart() {//끝나는 시간이 같은 노드들을 묶어 start 기준으로 퀵정렬
	int i,now=list[0].end;
	int count = 0;
	for (i = 0; i < n; i++) {
		if (list[i].end == now) {
			count++;
		}
		else {
			sorts(i - count, i - 1);
			count = 1;
			now = list[i].end;
		}
	}
	if (count != 1) {
		sorts(i - count, i - 1);
	}
}

void sorts(int left, int right) {//시작하는 시간 기준으로 퀵정렬
	int tmps;
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2].start;
	do {
		while (list[pl].start < x) {
			pl++;
		}
		while (list[pr].start > x) {
			pr--;
		}
		if (pl <= pr) {
			tmps = list[pr].start;
			list[pr].start = list[pl].start;
			list[pl].start = tmps;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		sorts(left, pr);
	}
	if (pl < right) {
		sorts(pl, right);
	}
}

int greedyCount() {//가능한 가장 빨리 끝나는 회의를 넣는다.
	int count = 1;
	int end = list[0].end;//첫번째 회의는 가장 빨리 끝나기 때문에 넣음
	int idx = 0;
	int i;
	for (i = idx+1; i < n; i++) {//정렬된 시간에 대해
		if (list[i].start >= end) {//다음 회의의 쉬는 시간이 끝나는 시간보다 늦거나 같으면
			idx = i;
			end = list[i].end;
			count++;//회의 넣음
		}
	}
	return count++;//회의 개수 반환j
}