#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main() {
	int num,i,a;
	int list[2000002] = { 0 };
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &a);
		list[a + 1000000]=1;
	}
	for (i = 0; i <= 2000001; i++) {
		if (list[i] != 0) {
			printf("%d\n", i - 1000000);
		}
	}

	return 0;
}
