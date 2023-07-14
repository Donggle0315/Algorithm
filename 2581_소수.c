#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int i,j,n, m,sum=0,min=-1;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++) {
		if (i == 2) {
			sum += i;
			min = i;
			continue;
		}
		for (j = 2; j <= i - 1; j++) {
			if (i % j == 0) {
				break;
			}
			if (j == i - 1) {
				sum += i;
				if (min == -1) {
					min = i;
				}
			}
		}
	}
	if (min == -1) {
		printf("%d", min);
	}
	else {
		printf("%d\n%d", sum, min);
	}


	return 0;
}