#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int n, a, b, re;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		re = 1;
		int div = 2;
		while (div <= a && div <= b) {
			if (a % div == 0 && b % div == 0) {
				re *= div;
				a /= div;
				b /= div;
				continue;
			}
			div++;
		}
		re *= a;
		re *= b;
		printf("%d\n", re);
	}

	return 0;

}