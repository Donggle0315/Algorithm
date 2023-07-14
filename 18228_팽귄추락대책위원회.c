#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int i, k, n;
	int flag = 0;
	int lmin = 1000000000;
	int rmin = 1000000000;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == -1) {
			flag = 1;
			continue;
		}
		if (flag == 0 && k < lmin) {
			lmin = k;
		}
		else if (flag==1&&k < rmin) {
			rmin = k;
		}
	}
	printf("%d", lmin + rmin);


	return 0;
}
