#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a, b,new_a=0,new_b=0;
	scanf("%d %d", &a, &b);
	while (a != 0) {
		new_a *= 10;
		new_a += (a % 10);
		a /= 10;
	}
	while (b != 0) {
		new_b *= 10;
		new_b += (b % 10);
		b /= 10;
	}
	a = new_a + new_b;
	while (a != 0) {
		b *= 10;
		b += (a % 10);
		a /= 10;
	}
	printf("%d", b);
	return 0;
}