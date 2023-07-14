#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word{
	char str[51];
	int len;
}word;

void init();
int compare(const void*, const void*);
void printing();
void finish();

word* list;
int n;

int main()
{
	init();
	qsort(list, n, sizeof(list[0]), compare);
	printing();
	finish();

	return 0;
}

void printing() {
	int i;
	for (i = 0; i < n; i++){
		printf("%s\n", list[i].str);
	}
}

void finish() {
	free(list);
}

void init() {
	int i, j;
	scanf("%d", &n);
	list = (word*)calloc(n + 1, sizeof(word));
	for (i = 0; i < n; i++){
		scanf(" %s", list[i].str);
		list[i].len = strlen(list[i].str);
		for (j = 0; j < i; j++){
			if (strcmp(list[i].str, list[j].str) == 0){
				i--;
				n--;
				break;
			}
		}
	}
}

int compare(const void* first, const void* second)
{
	word* a = (word*)first;
	word* b = (word*)second;

	if (a->len < b->len)
		return -1;
	else if (a->len > b->len)
		return 1;
	else if (a->len == b->len)
	{
		if (strcmp(a->str, b->str) < 0)
			return -1;
		else
			return 1;
	}
	return 0;
}
