#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,n,max=0;
	double sum=0, avg;
	int* list;

	scanf("%d", &n);
	list = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		if (list[i] > max) {
			max = list[i];
		}
	}
	for (i = 0; i < n; i++) {
		sum += (double)list[i]/max*100;
	}
	avg = sum / n;
	printf("%lf", avg);

	free(list);

	return 0;
}