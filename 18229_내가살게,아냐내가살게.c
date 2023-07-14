#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main() {
	int n, m, k, flag = 0;
	int i, j;
	int** list;
	scanf("%d %d %d", &n, &m, &k);
	list = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		list[i] = (int*)malloc(m*sizeof(int));
		for (j = 0; j < m; j++) {
			scanf("%d", &list[i][j]);
		}
	}
	

	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++) {
			if (i == 0&&list[j][i]>=k) {
				flag = 1;
				break;
			}
			else if (i != 0) {
				list[j][i] += list[j][i - 1];
				if (list[j][i] >= k) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) {
			break;
		}
	}
	printf("%d %d", j + 1, i + 1);

	for (i = 0; i < n; i++) {
		free(list[i]);
	}
	free(list);

	return 0;
}
