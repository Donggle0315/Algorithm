#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int i,j,n,m,sum,count;
	double avg,rate;
	int** list;

	scanf("%d", &n);
	list = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		list[i] = (int*)malloc(m * sizeof(int));
		sum = 0; 
		count = 0;
		for (j = 0; j < m; j++) {
			scanf("%d", &list[i][j]);
			sum += list[i][j];
		}
		avg = (double)sum / m;
		for (j = 0; j < m; j++) {
			if (avg < list[i][j]) {
				count++;
			}
		}
		rate = (double)count / m*100;
		printf("%0.3f%%\n", round(rate * 1000) / 1000);
	}



	return 0;
}