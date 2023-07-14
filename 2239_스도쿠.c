#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
void backtracking(int);
int isHere(int, int);
void printing();

int sdoku[9][9];
int blank[81][2];
int count = 0;
int flag = 0;

int main() {
	init();
	backtracking(0);

	return 0;
}

void backtracking(int depth) {
	int i;
	if (depth == count) {
		flag = 1;
		printing();
		return;
	}
	for (i = 1; i <= 9; i++) {
		if (flag == 0 && isHere(depth, i) == 1) {
			sdoku[blank[depth][0]][blank[depth][1]] = i;
			backtracking(depth + 1);
			sdoku[blank[depth][0]][blank[depth][1]] = 0;
		}
	}
}

int isHere(int b, int k) {
	int i, j;
	for (i = 0; i < 9; i++) {
		if (sdoku[i][blank[b][1]] == k) {
			return 0;
		}
	}
	for (i = 0; i < 9; i++) {
		if (sdoku[blank[b][0]][i] == k) {
			return 0;
		}
	}
	for (i = blank[b][0] / 3 * 3; i < blank[b][0] / 3 * 3 + 3; i++) {
		for (j = blank[b][1] / 3 * 3; j < blank[b][1] / 3 * 3 + 3; j++) {
			if (sdoku[i][j] == k) {
				return 0;
			}
		}
	}
	return 1;
}



void printing() {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d", sdoku[i][j]);
		}
		printf("\n");
	}
}

void init() {
	int i, j;
	char str[10];
	for (i = 0; i < 9; i++) {
		scanf("%s", str);
		for (j = 0; j < 9; j++) {
			sdoku[i][j] = str[j] - '0';
			if (sdoku[i][j] == 0) {
				blank[count][0] = i;
				blank[count++][1] = j;
			}
		}
	}
}