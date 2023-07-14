#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,k,max=0,min=0;
	scanf("%d", &n);
	scanf("%d", &k);
	max = k;
	min = k;
	for (int i = 1; i < n; i++) {
		scanf("%d", &k);
		if (k < min) {
			min = k;
		}
		if (k > max) {
			max = k;
		}
	}
	printf("%d", max * min);

	return 0;
}