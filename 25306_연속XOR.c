#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	a = a - 1;

	if (a % 4 == 0) {
		a = a;
	}
	else if (a % 4 == 1) {
		a = 1;
	}
	else if (a % 4 == 2) {
		a = a + 1;
	}
	else {
		a = 0;
	}
	if (b % 4 == 0) {
		b = b;
	}
	else if (b % 4 == 1) {
		b = 1;
	}
	else if (b % 4 == 2) {
		b = b + 1;
	}
	else {
		b = 0;
	}
	printf("%lld", a ^ b);
	return 0;
}