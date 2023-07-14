#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j,n,count,score;
	char** list;

	scanf("%d", &n);
	list = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		list[i] = (char*)malloc(81 * sizeof(char));
		scanf("%s", list[i]);
		count = 1;
		score = 0;
		for (j = 0; list[i][j] != '\0'; j++) {
			if (list[i][j] == 'O') {
				score += count++;
			}
			else {
				count = 1;
			}
		}
		printf("%d\n", score);
	}

	for (i = 0; i < n; i++) {
		free(list[i]);
	}
	free(list);


	return 0;
}