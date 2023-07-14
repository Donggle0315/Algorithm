#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int n, k, p,q;
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 1; i < n; i++) {
		scanf("%d", &p);
		q = k;
		int tmp = 2;
		while (p>=tmp&&q>=tmp) {
			if (p % tmp == 0 && q % tmp == 0) {
				p /= tmp;
				q /= tmp;
				continue;
			}
			tmp++;
		}
		printf("%d/%d\n", q, p);
	}



	return 0;
}