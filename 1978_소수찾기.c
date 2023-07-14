#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,x,i,j,count=0;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &x);
		if (x == 2) {
			count++;
		}
		for (j = 2; j <= x - 1; j++) {
			if (x % j == 0) {
				break;
			}
			if (j == x - 1) {
				count++;
			}
		}
	}
	printf("%d", count);


	return 0;
}