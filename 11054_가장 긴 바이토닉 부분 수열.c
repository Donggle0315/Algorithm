#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void findBeforeDecreaseSet();
void findAfterIncreaseSet();
int findMaxLength();


int n;
int input[1000];
int increase[1000];
int decrease[1000];

int main() {
	init();
	findBeforeDecreaseSet();
	findAfterIncreaseSet();
	printf("%d", findMaxLength());

	return 0;
}


void init() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
}

void findBeforeDecreaseSet() {
	int i,j,tmp;
	decrease[0] = 1;
	for (i = 1; i < n; i++) {
		tmp = 0;
		for (j = 0; j < i; j++) {
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
	increase[n-1] = 1;
	for (i = n-2; i >=0; i--) {
		tmp = 0;
		for (j = i+1; j < n; j++) {
			if (input[i] <= input[j]) {
				continue;
			}
			if (tmp < increase[j]) {
				tmp = increase[j];
			}
		}
		increase[i] = tmp + 1;
	}
}

int findMaxLength() {
	int max = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (increase[i] + decrease[i] > max) {
			max = increase[i] + decrease[i];
		}
	}
	return max-1;
}