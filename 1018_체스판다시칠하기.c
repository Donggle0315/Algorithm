#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, n,i,j,p,q,count,min=64;
	char** board;
	scanf("%d %d", &n, &m);
	board = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		board[i] = (char*)malloc((m+1) * sizeof(char));
		scanf("%s", board[i]);
	}

	for (i = 0; i <= n - 8; i++) {
		for (j = 0; j <= m - 8; j++) {
			count= 0;
			//첫번째가 B인경우
			for (p = i; p < i + 8; p++) {
				for (q = j; q < j + 8; q++) {
					if (((p - i) + (q - j)) % 2 == 0 && board[p][q] == 'W') {
						count++;
					}
					if (((p - i) + (q - j)) % 2 == 1 && board[p][q] == 'B') {
						count++;
					}
				}
			}
			if (count < min) {
				min = count;
			}

			count = 0;
			//첫번째가 W인경우
			for (p = i; p < i + 8; p++) {
				for (q = j; q < j + 8; q++) {
					if (((p - i) + (q - j)) % 2 == 0 && board[p][q] == 'B') {
						count++;
					}
					if (((p - i) + (q - j)) % 2 == 1 && board[p][q] == 'W') {
						count++;
					}
				}
			}
			if (count < min) {
				min = count;
			}
		}
	}

	printf("%d", min);




	for (i = 0; i < n; i++){
		free(board[i]);
	}
	free(board);


	return 0;
}