#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int t;
	int a, b, c;
	int n;
	scanf("%d", &t);
	for (int p = 0; p < t; p++) {
		n = 0;
		scanf("%d %d %d", &a, &b, &c);
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				for (int k = i; k <= c; k++) {
					if (i % j != j % k) {
						continue;
					}
					if (j % k != k % i) {
						continue;
					}
					if (i % j != k % i) {
						continue;
					}
					n++;
				}
			}
		}
		printf("%d\n", n);
	}

	return 0;
}