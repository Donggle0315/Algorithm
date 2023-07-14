#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	int old;
	char name[101];
}person;

int main() {
	int num,i,j;
	char* tmp=(char*)malloc(101*sizeof(char));
	person* list;
	scanf("%d", &num);
	list = (person*)malloc(num * sizeof(person));
	for (i = 0; i < num; i++) {
		scanf("%d %s", &list[i].old, tmp);
		strcpy(&list[i].name, tmp);
	}

	for (i = 1; i <= 200; i++) {
		for (j = 0; j < num; j++) {
			if (list[j].old == i) {
				printf("%d %s\n", list[j].old, list[j].name);
			}
		}
	}

	free(list);
	free(tmp);

	return 0;
}