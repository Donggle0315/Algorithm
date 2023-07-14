#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,i,j,k,n,sum,p,q;
	int** list;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &k);
		scanf("%d", &n);
		list = (int**)malloc((k + 1) * sizeof(int*));
		for (j = 0; j < k + 1; j++) {
			list[j] = (int*)calloc(n, sizeof(int));
		}
		for (j = 0; j < n; j++) {
			list[0][j] = j + 1;
		}
		for (j = 1; j < k + 1; j++) {
			for(p=0;p<n;p++){
				for (q = 0; q <= p; q++) {
					list[j][p] += list[j - 1][q];
				}
			}
		}
		printf("%d\n", list[k][n-1]);
		for (j = 0; j < k + 1; j++) {
			free(list[j]);
		}
		free(list);
	}


	return 0;
}