#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void findBeforeDecreaseSet();
void findAfterIncreaseSet();
int findMaxLength();

int n;
int input[501] = { 0 };
int increase[501] = { 0 };
int decrease[501] = { 0 };



int main() {
	init();
	findAfterIncreaseSet();
	findBeforeDecreaseSet();
	printf("%d", n - findMaxLength());


	return 0;
}


void init() {
	int i, x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		input[x] = y;
	}
}

void findBeforeDecreaseSet() {
	int i, j, tmp;
	decrease[1] = 1;
	for (i = 2; i < 501; i++) {
		if (input[i] == 0) {
			continue;
		}
		tmp = 0;
		for (j = 1; j < i; j++) {
			if (input[j] == 0) {
				continue;
			}
			if (input[i] <= input[j]) {
				continue;
			}
			if (tmp < decrease[j]) {
				tmp = decrease[j];
			}
		}
		decrease[i] = tmp + 1;
	}
}

void findAfterIncreaseSet() {
	int i, j, tmp;
	increase[500] = 1;
	for (i = 499; i >=1; i--) {
		if (input[i] == 0) {
			continue;
		}
		tmp = 0;
		for (j = i+1; j < 501; j++) {
			if (input[j] == 0) {
				continue;
			}
			if (input[i] >= input[j]) {
				continue;
			}
			if (tmp < increase[j]) {
				tmp = increase[j];
			}
		}
		increase[i] = tmp +1;
	}
}

int findMaxLength() {
	int max = 0;
	int i;
	for (i = 1; i < 501; i++) {
		if (increase[i] + decrease[i] > max) {
			max = increase[i] + decrease[i];
		}
	}

	return max -1;
}