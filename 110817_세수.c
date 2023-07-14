#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if ((a >= b && b >= c)||(c>=b&&b>=a)) {
		printf("%d", b);
	}
	else if ((c >= a && a >= b) || (b >= a && a >= c)) {
		printf("%d", a);
	}
	else {
		printf("%d", c);
	}

	return 0;
}