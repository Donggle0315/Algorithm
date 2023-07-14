#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int n,i,j;

	scanf("%d", &n);
	for (i = 1, j = 1; i < n; i += 6 * j, j++) {
		;
		//마지막 방 일반식 a1=1, an=a(n-1)+6n
	}
	printf("%d", j);

	return 0;
}