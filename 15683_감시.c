#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct cctv {
	int num;
	int row;
	int col;
	int dir;//1번은 4방향 / 2번은 2방향 / 3번은 4방향 / 4번은 4방향 / 5번 1방향
}cctv;

void init();
void finish();
void locateCCTV(int);

int n, m;
int** list;
int** copy;
cctv cctvList[8];
int cctvCount;
int min;

int main() {
	init();
	locateCCTV(0);
	printf("%d", min);
	finish();

	return 0;
}

int countArea() {
	int count = 0;
	copy = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		copy[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++) {
			copy[i][j] = list[i][j];
		}
	}

	for (int i = 0; i < cctvCount; i++) {
		switch (cctvList[i].num) {
		case 1:
			switch (cctvList[i].dir) {
				case 0:
					for (int j = cctvList[i].row; j < n; j++) {
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					break;
				case 1:
					for (int j = cctvList[i].col; j < m; j++) {
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					break;
				case 2:
					for (int j = cctvList[i].row; j >= 0; j--) {
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					break;
				case 3:
					for (int j = cctvList[i].col; j >= 0; j--) {
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					break;
			}
			break;
		case 2:
			switch (cctvList[i].dir) {
				case 0:
					for (int j = cctvList[i].row; j < n; j++) {
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					for (int j = cctvList[i].row; j >= 0; j--) {
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					break;
				case 1:
					for (int j = cctvList[i].col; j < m; j++) {
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					for (int j = cctvList[i].col; j >= 0; j--) {
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					break;
			}
			break;
		case 3:
			switch (cctvList[i].dir) {
				case 0:
					for (int j = cctvList[i].row; j < n; j++) {//아래로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					for (int j = cctvList[i].col; j < m; j++) {//오른쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					break;
				case 1:
					for (int j = cctvList[i].col; j < m; j++) {//오른쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					for (int j = cctvList[i].row; j >= 0; j--) {//위로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					break;
				case 2:
					for (int j = cctvList[i].row; j >= 0; j--) {//위로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					for (int j = cctvList[i].col; j >= 0; j--) {//왼쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					break;
				case 3:
					for (int j = cctvList[i].col; j >= 0; j--) {//왼쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					for (int j = cctvList[i].row; j < n; j++) {//아래로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					break;
			}
			break;
		case 4:
			switch (cctvList[i].dir) {
				case 0:
					for (int j = cctvList[i].row; j < n; j++) {//아래로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					for (int j = cctvList[i].col; j < m; j++) {//오른쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					for (int j = cctvList[i].col; j >= 0; j--) {//왼쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					break;
				case 1:
					for (int j = cctvList[i].col; j < m; j++) {//오른쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					for (int j = cctvList[i].row; j >= 0; j--) {//위로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					for (int j = cctvList[i].col; j >= 0; j--) {//왼쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					break;
				case 2:
					for (int j = cctvList[i].row; j >= 0; j--) {//위로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					for (int j = cctvList[i].col; j >= 0; j--) {//왼쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					for (int j = cctvList[i].row; j < n; j++) {//아래로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					break;
				case 3:
					for (int j = cctvList[i].row; j >= 0; j--) {//위로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					for (int j = cctvList[i].col; j < m; j++) {//오른쪽
						if (copy[cctvList[i].row][j] == 6) {
							break;
						}
						if (copy[cctvList[i].row][j] != 0) {
							continue;
						}
						copy[cctvList[i].row][j] = 7;
					}
					for (int j = cctvList[i].row; j < n; j++) {//아래로
						if (copy[j][cctvList[i].col] == 6) {
							break;
						}
						if (copy[j][cctvList[i].col] != 0) {
							continue;
						}
						copy[j][cctvList[i].col] = 7;
					}
					break;
			}
			break;
		case 5:
			for (int j = cctvList[i].row; j < n; j++) {//아래로
				if (copy[j][cctvList[i].col] == 6) {
					break;
				}
				if (copy[j][cctvList[i].col] != 0) {
					continue;
				}
				copy[j][cctvList[i].col] = 7;
			}
			for (int j = cctvList[i].row; j >= 0; j--) {//위로
				if (copy[j][cctvList[i].col] == 6) {
					break;
				}
				if (copy[j][cctvList[i].col] != 0) {
					continue;
				}
				copy[j][cctvList[i].col] = 7;
			}
			for (int j = cctvList[i].col; j < m; j++) {//오른쪽
				if (copy[cctvList[i].row][j] == 6) {
					break;
				}
				if (copy[cctvList[i].row][j] != 0) {
					continue;
				}
				copy[cctvList[i].row][j] = 7;
			}
			for (int j = cctvList[i].col; j >= 0; j--) {//왼쪽
				if (copy[cctvList[i].row][j] == 6) {
					break;
				}
				if (copy[cctvList[i].row][j] != 0) {
					continue;
				}
				copy[cctvList[i].row][j] = 7;
			}
			break;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy[i][j] == 0) {
				count++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		free(copy[i]);
	}
	free(copy);

	return count;
}

void locateCCTV(int depth) {
	if (depth == cctvCount) {
		int k = countArea();
		if (k < min) {
			min = k;
		}
		return;
	}
	int c = cctvList[depth].num;
	switch (c) {
	case 1:
		for (int i = 0; i < 4; i++) {
			cctvList[depth].dir = i;
			locateCCTV(depth + 1);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			cctvList[depth].dir = i;
			locateCCTV(depth + 1);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			cctvList[depth].dir = i;
			locateCCTV(depth + 1);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			cctvList[depth].dir = i;
			locateCCTV(depth + 1);
		}
		break;
	case 5:
		cctvList[depth].dir = 0;
		locateCCTV(depth + 1);
		break;
	}

}

void init() {
	scanf("%d %d", &n, &m);
	list = (int**)malloc(n * sizeof(int*));
	cctvCount = 0;
	for (int i = 0; i < n; i++) {
		list[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++) {
			scanf("%d", &list[i][j]);
			if (1 <= list[i][j] && list[i][j] <= 5) {
				cctvList[cctvCount].num = list[i][j];
				cctvList[cctvCount].row = i;
				cctvList[cctvCount++].col = j;
			}
		}

	}
	min = n * m + 1;
}

void finish() {
	for (int i = 0; i < n; i++) {
		free(list[i]);
	}
	free(list);
}