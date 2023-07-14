#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, k,i,tmp,count=0;
	int* coin;
	
	scanf("%d %d", &n, &k);
	coin = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	for (i = n - 1; i >= 0; i--) {
		if (k / coin[i] != 0) {
			tmp = k / coin[i];
			count += tmp;
			k -= tmp * coin[i];
		}
	}

	printf("%d", count);


	return 0;
}