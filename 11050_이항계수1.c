#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int n, k,a=1,b=1,i;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= k;n--, i++) {
		a *= n;
		b *= i;
	}
	a /= b;
	printf("%d", a);

	return 0;
}