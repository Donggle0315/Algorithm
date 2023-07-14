#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	char* list;
	int i,num,sum=0;
	scanf("%d", &num);
	list = (char*)malloc((num+1) * sizeof(char));
	scanf("%s", list);
	for (i = 0; i < num; i++) {
		sum += (list[i] - '0');
	}
	printf("%d", sum);

	free(list);

	return 0;
}