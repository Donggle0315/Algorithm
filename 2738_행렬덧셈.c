#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j, m,n;
	int** la;
	int** lb;

	scanf("%d %d", &m, &n);
	la = (int**)malloc(m * sizeof(int*));
	lb = (int**)malloc(m * sizeof(int*));

	for (i = 0; i < m; i++) {
		la[i] = (int*)malloc(n * sizeof(int));
		lb[i] = (int*)malloc(n * sizeof(int));
	}

	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &la[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &lb[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", la[i][j] + lb[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < m; i++) {
		free(la[i]);
		free(lb[i]);
	}
	free(la);
	free(lb);


	return 0;
}