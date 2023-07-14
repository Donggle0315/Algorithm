#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,n;
	int list[31] = { 0 };

	for (i = 0; i < 30; i++) {
		scanf("%d", &n);
		list[n] = 1;
	}
	for (i = 1; i <= 30; i++) {
		if (list[i] == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}