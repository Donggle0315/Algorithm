#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void init();
void finish();
int HowMuch(int, int);
void cal();

int n, m;
int sum = 0;
int** money;
int* way;


int main() {
	init();
	cal();
	finish();


	return 0;
}

void cal() {
	int i;
	for (i = 0; i < m - 1; i++) {
		sum += HowMuch(way[i], way[i + 1]);
	}
	printf("%d", sum);
}


int HowMuch(int a, int b) {
	return money[a-1][b-1];
}

void init() {
	int i,j;
	scanf("%d %d", &n, &m);
	way = (int*)malloc(m * sizeof(int));
	money = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < m; i++) {
		scanf("%d", &way[i]);
	}
	for (i = 0; i < n; i++) {
		money[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			scanf("%d", &money[i][j]);;
		}
	}
}

void finish() {
	int i;
	for (i = 0; i < n; i++) {
		free(money[i]);
	}
	free(money);
	free(way);
}