#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int CalMoney(int,int,int);

int main() {
	int d1, d2, d3;
	scanf("%d %d %d", &d1, &d2, &d3);
	printf("%d", CalMoney(d1, d2, d3));

	return 0;
}

int CalMoney(int a, int b, int c) {
	if (a == b && b == c) {
		return 10000 + a * 1000;
	}
	if (a == b || a == c) {
		return 1000 + a * 100;
	}
	if (b == c) {
		return 1000 + b * 100;
	}
	if (a >= b && a >= c) {
		return a * 100;
	}
	if (b >= a && b >= c) {
		return b * 100;
	}
	return c * 100;
}