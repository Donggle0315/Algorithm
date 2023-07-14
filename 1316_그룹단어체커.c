#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j,num,flag=0,count=0;
	char* word;
	int* alpha;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		word = (char*)malloc(sizeof(char)* 101);
		alpha = (int*)calloc(26, sizeof(int));
		scanf("%s", word);
		alpha[word[0] - 'a']++;
		for (j = 1; word[j] != '\0'; j++) {
			if (word[j - 1] == word[j]) {
				continue;
			}
			if (alpha[word[j] - 'a'] != 0) {
				flag = 1;
				break;
			}
			alpha[word[j] - 'a']++;
		}

		if (flag == 0) {
			count++;
		}
		else{
			flag = 0;
		}

		free(word);
		free(alpha);
	}

	printf("%d", count);


	return 0;
}