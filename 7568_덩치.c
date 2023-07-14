#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct human {
	int kg;
	int cm;
	int grade;
}human;


void init();
void finish();
void sort();
void printing();

int n;
human* list;

int main() {
	init();
	sort();
	printing();
	finish();

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	list = (human*)malloc(n * sizeof(human));
	for (i = 0; i < n; i++) {
		scanf("%d %d", &list[i].kg, &list[i].cm);
	}
}

void printing() {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", list[i].grade);
	}
}

void sort() {
	int i, j, rank;
	for (i = 0; i < n; i++) {
		rank = 1;
		for (j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (list[i].cm < list[j].cm && list[i].kg < list[j].kg) {
				rank++;
			}
		}
		list[i].grade = rank;
	}
}


void finish() {
	free(list);
}