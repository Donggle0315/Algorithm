#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c, n;
	scanf("%d %d %d", &a, &b, &c);
	for (n = 0; c!=b&&n <= a / (c - b); n++) {
		;
	}
	/*
	a+b*n<c*n
	a<(c-b)*n
	a/(c-b)<n
	*/
	if (n == 0) {
		n = -1;
	}
	
	printf("%d", n);

	return 0;
}