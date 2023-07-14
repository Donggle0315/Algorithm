#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* str = (char*)malloc(101 * sizeof(char));
	scanf("%s", str);
	printf("%d", strlen(str));
	free(str);

	return 0;
}