#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int n, i,j,k,min=0;
	scanf("%d", &n);
	for (i = n - 1; i > 0; i--) {
		j = i;
		k = i;
		while (j != 0) {
			k += (j % 10);
			j /= 10;
		}
		if (k == n) {
			min = i;
		}
	}
	printf("%d\n", min);

	return 0;
}