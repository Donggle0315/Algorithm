#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int x,i,j;
	scanf("%d", &x);

	for (i = 1, j = 1; i <= x; i += j,j++) {
		;
	}
	if ((j - 1) % 2 == 1) {
		printf("%d/%d", i-x,j - (i - x));
	}
	else {
		printf("%d/%d", j - (i - x), i - x);
	}

	return 0;
}