#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
	int a, b;
	int count = 0;
	scanf("%d", &a);
	b = (~a)+1;
	
	
	for (int i = 31; i >= 0;i--) {
		int re1 = a >> i & 1;
		int re2 = b >> i & 1;
		if (re1 != re2) {
			count++;
		}
	}
	printf("%d", count);

	return 0;
}