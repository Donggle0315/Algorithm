#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	int num,i;
	char* str;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		str = (char*)malloc(1000 * sizeof(char));
		scanf("%s", str);
		printf("%c%c\n", str[0], str[strlen(str) - 1]);
		free(str);
	}

	return 0;
}