#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
	int count2 = 0, count5 = 0, i,n,num,count=0;
	scanf("%d", &num);

	for (i = num; i > 0; i--) {
		n = i;
		while (n % 2 == 0) {
			count2++;
			n /= 2;
		}
		while (n % 5 == 0) {
			count5++;
			n /= 5;
		}
	}

	for (count = 0; count2 > 0 && count5 > 0; count++, count2--, count5--) {
		;
	}
	printf("%d", count);

	return 0;
}