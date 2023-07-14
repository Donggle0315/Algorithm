#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* sentence;
	int i,j,flag=0;

	while (1) {
		sentence = (char*)malloc(6 * sizeof(char));
		scanf("%s", sentence);
		if (strcmp(sentence, "0") == 0) {
			break;
		}
		for (i = 0, j = strlen(sentence) - 1; i <= j; i++, j--) {
			if (sentence[i] != sentence[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			flag = 0;
			printf("no\n");
		}
		else {
			printf("yes\n");
		}
		free(sentence);
	}



	return 0;
}