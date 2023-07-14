#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init();
void makeLine(int,int);
void printLine(int);
int* line;

int main() {
	init();

	return 0;
}

void init() {
	int n,total;
	while (scanf("%d", &n) != EOF) {
		total = pow(3, n);
		line = (int*)calloc(total, sizeof(int));
		makeLine(total, 0);
		printLine(total);
		free(line);
	}	
}

void makeLine(int total,int start) {
	int i;
	int a = total / 3;
	if (total == 1) {
		return;
	}
	else {
		makeLine(a, start);
		for (i = start + a; i < start + 2 * a; i++) {
			line[i] = 1;
		}
		makeLine(a, start + 2 * a);
	}
}

void printLine(int total) {
	int i;
	for (i = 0; i < total; i++) {
		if (line[i] == 0) {
			printf("-");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");
}