#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void d(int*,int);

int main() {
	int i,num;
	int* list = calloc(10001, sizeof(int));
	for (i = 1;i<10000; i++) {
		d(list,i);
	}
	for (i = 1; i <= 10000; i++) {
		if (list[i] == 0) {
			printf("%d\n", i);
		}
	}

	free(list);
	return 0;
}

void d(int* list,int n) {
	int k = n;
	while (n != 0) {
		k += n % 10;
		n /= 10;
	}
	if (k<=10000&&list[k] == 0) {
		list[k]++;
		d(list,k);
	}
}