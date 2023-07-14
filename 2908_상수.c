#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	char* n1 = (char*)malloc(3 * sizeof(char));
	char* n2 = (char*)malloc(3 * sizeof(char));

	int i,num1=0, num2=0;

	scanf("%s %s", n1, n2);
	for (i = 2; i >= 0; i--) {
		num1 += (int)(n1[i] - '0') * pow(10, i);
	}
	for (i = 2; i >= 0; i--) {
		num2 += (int)(n2[i] - '0') * pow(10, i);
	}

	if (num1 < num2) {
		printf("%d", num2);
	}
	else {
		printf("%d", num1);
	}

	free(n1);
	free(n2);

	return 0;
}