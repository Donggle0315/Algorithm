#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a, b, x = 1, y = 1, i = 2, j;
	scanf("%d %d", &a, &b);

	j = a > b ? b : a;
	while(i <= j) {
		if (a % i == 0 && b % i == 0) {
			x *= i;
			a /= i;
			b /= i;
		}
		else {
			i++;
		}
	}
	y = x * a * b;
	printf("%d\n%d", x, y);

	return 0;
}