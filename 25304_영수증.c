#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
	int money,i,num,a,b;
	scanf("%d", &money);
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &a, &b);
		money -= (a * b);
	}
	if (money == 0) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}