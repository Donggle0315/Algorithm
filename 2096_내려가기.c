#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void findMax(int, int, int);
void findMin(int, int, int);
int Max(int, int);
int Min(int, int);
void print();

int n;
int max[2][3];
int min[2][3];

int main() {
	init();
	print();

	return 0;
}

void print() {
	printf("%d %d", Max(Max(max[0][0], max[0][1]), max[0][2]), Min(Min(min[0][0], min[0][1]), min[0][2]));
}

void init() {
	int i,a,b,c;
	scanf("%d", &n);
	max[0][0] = max[0][1] = max[0][2] = 0;
	min[0][0] = min[0][1] = min[0][2] = 0;
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		findMax(a, b, c);
		findMin(a, b, c);
	}
}

void findMax(int a, int b, int c) {
	max[1][0] = a + Max(max[0][0],max[0][1]);
	max[1][1] = b + Max(Max(max[0][0],max[0][1]),max[0][2]);
	max[1][2] = c + Max(max[0][1],max[0][2]);
	max[0][0] = max[1][0];
	max[0][1] = max[1][1];
	max[0][2] = max[1][2];
}

void findMin(int a, int b, int c) {
	min[1][0] = a + Min(min[0][0], min[0][1]);
	min[1][1] = b + Min(Min(min[0][0], min[0][1]), min[0][2]);
	min[1][2] = c + Min(min[0][1], min[0][2]);
	min[0][0] = min[1][0];
	min[0][1] = min[1][1];
	min[0][2] = min[1][2];
}

int Max(int a, int b) {
	return a > b ? a : b;
}

int Min(int a, int b) {
	return a > b ? b : a;
}