#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	int i;
	char* str = (char*)malloc(101 * sizeof(char));
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++) {
		if (isupper(str[i])) {
			printf("%c", tolower(str[i]));
		}
		else {
			printf("%c", toupper(str[i]));
		}
	}
	
	free(str);

	return 0;
}