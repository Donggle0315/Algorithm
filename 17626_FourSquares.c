#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* list;
int num;

void init();
void finish();
int cal();

int main() {
	scanf("%d", &num);
	init();
	printf("%d", cal());

	finish();

	return 0;
}

int cal() {
	int min,i,j,a;
	for (i = 2; i <= num; i++) {
		if (list[i] != 0) {
			continue;
		}
		min = -1;
		a = (int)sqrt(i);
		for (j = a; j >= 1; j--) {
			if (list[i - j * j] != 0) {
				if (min == -1 || min > list[i - j * j]) {
					if (list[i-j*j] >= 4) {
						continue;
					}
					min = list[i - j * j];
				}
			}
		}
		list[i] = min + 1;
	}

	
	return list[num];
}


void init() {
	int i;
	list = (int*)calloc(num + 1, sizeof(int));
	for (i = 1; pow(i, 2) <= num; i++) {
		list[(int)pow(i, 2)] = 1;
	}
}

void finish() {
	free(list);
}