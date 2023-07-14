#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num,a=2,i,flag=0;
	scanf("%d", &num);
	while (num != 1) {
		if (num % a == 0) {
			printf("%d\n", a);
			num /= a;
		}	
		else {
			a++;
		}
	}


	return 0;
}