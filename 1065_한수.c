#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

bool checking(int);

int main() {
	int i, n, count = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (checking(i) == true) {
			count++;
		}
	}
	printf("%d", count);

	return 0;
}

bool checking(int n) {
	int d1, d2;
	while (n/100 != 0) {
		d1 = n%1000 / 100 - n % 100 / 10;
		d2 = n %100/ 10 - n % 10;
		if (d1 != d2) {
			return false;
		}
		n /= 10;
	}
	return true;
}