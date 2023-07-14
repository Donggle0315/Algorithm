#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init(int);
void finish();
int cal(int);

int* list;



int main() {
	int num;
	scanf("%d", &num);
	init(num);
	printf("%d", cal(num));

	return 0;
}

int cal(int num) {
	int i;
	int min;
	if (num == 1 || num == 2 || num == 3) {
		return list[num];
	}
	for (i = 4; i <= num; i++) {
		min = list[i - 1];
		if (i % 3 == 0 && list[i / 3] < min) {
			min = list[i / 3];
		}
		if (i % 2 == 0 && list[i / 2] < min) {
			min = list[i / 2];
		}
		list[i] = min + 1;
	}
	return list[num];
}


void init(int num) {
	list = (int*)malloc((num+1) * sizeof(int));
	list[1] = 0;
	list[2] = 1;
	list[3] = 1;
}

void finish() {
	free(list);
}