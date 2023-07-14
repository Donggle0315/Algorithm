#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define ROW 12
#define COL 6

void init();
void play();
void re_init();
void makeField();
void dfs(int, int,char);

char board[12][6];
int visited[12][6] = { 0 };
int score;//연쇄 횟수
int block;
int deleteBox[72][2];
int dc;
int boom;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int main() {
	init();
	play();
	printf("%d", score);


	return 0;
}

void play() {
	while (1) {
		boom = 0;
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (board[i][j] != '.' && visited[i][j] == 0) {
					block = 0;
					dfs(i, j,board[i][j]);
					if (block >= 4) {
						for (int k = 0; k < block; k++) {
							board[deleteBox[k][0]][deleteBox[k][1]] = '.';
						}
					}
					
				}
			}
		}
		if (boom == 0) {//파괴 가능한 집합이 없거나, 블럭이 더 이상 없다면
			break;
		}
		
		makeField();//아래로 다 내림
		re_init();
		score++;
	}
}

void re_init() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			visited[i][j] = 0;
		}
	}
}

void makeField() {
	for (int i = 0; i < COL; i++) {
		char str[ROW];
		int sc = 0;
		for (int j = ROW - 1; j >= 0; j--) {
			if (board[j][i] != '.') {
				str[sc++] = board[j][i];
				board[j][i] = '.';
			}
		}
		for (int j = 0; j < sc; j++) {
			board[ROW-1-j][i] = str[j];
		}
	}
}

void dfs(int r, int c, char color) {
	visited[r][c] = 1;
	deleteBox[block][0] = r;
	deleteBox[block++][1] = c;
	for (int i = 0; i < 4; i++) {
		int p = r + dir[i][0];
		int q = c + dir[i][1];
		if (p < 0 || p >= ROW || q < 0 || q >= COL) {
			continue;
		}
		if (board[p][q] !=color) {
			continue;
		}
		if (visited[p][q] != 0) {
			continue;
		}
		dfs(p, q,color);
	}
	if (block >= 4) {
		boom=1;
	}
}

void init() {
	score = 0;
	for (int i = 0; i < ROW; i++) {
		char str[COL+1];
		scanf("%s", str);
		for (int j = 0; j < COL; j++) {
			board[i][j] = str[j];
		}
	}
}