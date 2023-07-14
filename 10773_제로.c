#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num, i,a, sum = 0,re=0;
	int* recent;

	scanf("%d", &num);
	recent = (int*)malloc(num * sizeof(int));
	for (i = 0; i < num; i++) {
		scanf("%d", &a);
		if (a != 0) {
			sum += a;
			recent[re++] = a;
		}
		else {
			sum -= recent[--re];
		}
	}
	printf("%d", sum);

	free(recent);

	return 0;
}