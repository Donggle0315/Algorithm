#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	long long a, b;
	scanf("%ld %ld", &a, &b);
	if (a > b) {
		printf("%ld", a - b);
	}
	else {
		printf("%ld", b - a);
	}


	return 0;
}