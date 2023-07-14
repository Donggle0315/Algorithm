#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
typedef struct island {
	int h;//높이
	int w;//너비
	int** map;//지도
	int** visited;//방문 여부 0 없음 1 있음
	int count;//섬의 개수
}island;

int init();
//동적 배열 할당 및 입력
void finish();
//동적 해제
void dfs(int, int);
//dfs를 통해 하나의 연결된 섬 찾기
int findIsland();
//dfs를 몇번 했냐에 따라 섬의 개수 반환

island* ip;
int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };//8방향을 좌표로 표현

int main() {
	int re;
	while (1) {
		re = init();
		if (re == 1) {//0 0 입력
			free(ip);
			break;
		}
		printf("%d\n", findIsland());
		finish();
	}
}

int findIsland() {
	int i, j;
	for (i = 0; i < ip->h; i++) {
		for (j = 0; j < ip->w; j++) {
			if (ip->map[i][j] == 0) {//육지가 아니면
				continue;
			}
			if (ip->visited[i][j] == 1) {//이미 방문 했다면
				continue;
			}
			dfs(i, j);
			(ip->count)++;//섬의 개수 +1
		}
	}
	return ip->count;
}


void dfs(int y, int x) {
	int i, p, q;
	ip->visited[y][x] = 1;//방문 체크
	for (i = 0; i < 8; i++) {//8가지 방향으로 조사
		p = dir[i][0];
		q = dir[i][1];
		if (y + p < 0 || y + p >= ip->h) {//y좌표가 범위 안인지 조사
			continue;
		}
		if (x + q < 0 || x + q >= ip->w) {//x좌표가 범위 안인지 조사
			continue;
		}
		if (ip->map[y + p][x + q] == 0) {//육지가 아니라면
			continue;
		}
		if (ip->visited[y + p][x + q] == 1) {//이미 방문 했다면
			continue;
		}
		dfs(y + p, x + q);
	}
}

int init() {
	int i, j;
	ip = (island*)malloc(sizeof(island));
	scanf("%d %d", &ip->w, &ip->h);
	if (ip->w == 0 && ip->h == 0) {// 0 0 입력되면 종료
		return 1;
	}
	ip->map = (int**)malloc(ip->h * sizeof(int*));
	ip->visited = (int**)malloc(ip->h * sizeof(int*));
	for (i = 0; i < ip->h; i++) {
		ip->map[i] = (int*)malloc(ip->w * sizeof(int));
		ip->visited[i] = (int*)calloc(ip->w, sizeof(int));
		for (j = 0; j < ip->w; j++) {
			scanf("%d", &ip->map[i][j]);
		}
	}
	ip->count = 0;
	
	return 0;
}

void finish() {
	int i;
	for (i = 0; i < ip->h; i++) {
		free(ip->map[i]);
		free(ip->visited[i]);
	}
	free(ip->map);
	free(ip->visited);
	free(ip);
}