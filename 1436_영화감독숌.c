#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num,i,j,k;

	scanf("%d", &num);

	for (i = 666, j = 0; j < num; i++) {
		k = i;
		while (k != 0) {
			if (k % 1000 == 666) {
				j++;
				break;
			}
			k /= 10;
		}
	}
	printf("%d", i-1);



	return 0;
}