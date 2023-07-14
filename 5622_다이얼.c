#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int list[8] = { 2,5,8,11,14,18,21,25 };
	int i,j,count = 0;
	char* s = (char*)malloc(15 * sizeof(char));
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++) {
		for (j = 0; j < 8; j++) {
			if (list[j] >= s[i] - 'A') {
				count += j + 3;
				break;
			}
		}
	}
	printf("%d", count);

	
	free(s);

	return 0;
}