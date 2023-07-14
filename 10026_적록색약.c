#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct picture {
	int n;//가로,세로
	char** pic;//색 정보 저장
	int** visited;//방문 여부
	int count;//구역 개수
}picture;

void init();
//동적 배열 할당 및 입력
void finish();
//동적 해제
void normaldfs(int,int,char);
//정상인이 본 시점으로 dfs
int dfscount(int);
//dfs를 한 결과의 구역 개수 반환 0이면 정상, 1이면 적록색약 경우로 계산
void abnormaldfs(int,int,char);
//적록색약인이 본 시점으로 dfs
void initVisited();
//gp->visited 배열 초기화

picture* gp;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상하좌우 방향

int main() {
	init();
	printf("%d ", dfscount(0));
	initVisited();
	printf("%d", dfscount(1));
	finish();

	return 0;
}

void initVisited() {
	int i, j;
	for (i = 0; i < gp->n; i++) {
		for (j = 0; j < gp->n; j++) {
			gp->visited[i][j] = 0;
		}
	}
}

int dfscount(int k) {
	int count = 0;
	int i,j;
	if (k == 0) {//정상인
		for (i = 0; i < gp->n; i++) {
			for (j = 0; j < gp->n; j++) {
				if (gp->visited[i][j] == 0) {//방문하지 않았다면
					normaldfs(j, i, gp->pic[i][j]);//dfs실시
					count++;//구역 +1
				}
			}
		}
	}
	else {//적록색약인
		for (i = 0; i < gp->n; i++) {
			for (j = 0; j < gp->n; j++) {
				if (gp->visited[i][j] == 0) {//방문하지 않았다면
					abnormaldfs(j, i, gp->pic[i][j]);//dfs실시
					count++;//구역 +1
				}
			}
		}
	}
	
	return count;
}

void normaldfs(int x, int y,char c) {
	int i, p, q;
	gp->visited[y][x] = 1;
	for (i = 0; i < 4; i++) {//상하좌우에 대해
		p = dir[i][0];
		q = dir[i][1];
		if (y + p < 0 || y + p >= gp->n) {//구역밖
			continue;
		}
		if (x+ q < 0 || x + q >= gp->n) {//구역 밖
			continue;
		}
		if (gp->pic[y + p][x + q] != c) {//색깔이 다른 경우
			continue;
		}
		if (gp->visited[y + p][x + q] == 1) {//이미 방문한 경우
			continue;
		}
		normaldfs(x + q, y + p, c);
	}
}

void abnormaldfs(int x, int y, char c) {
	int i, p, q;
	gp->visited[y][x] = 1;
	for (i = 0; i < 4; i++) {//상하좌우에 대해
		p = dir[i][0];
		q = dir[i][1];
		if (y + p < 0 || y + p >= gp->n) {//구역 밖
			continue;
		}
		if (x + q < 0 || x + q >= gp->n) {//구역 밖
			continue;
		}
		if (gp->visited[y + p][x + q] == 1) {//이미 방문한 경우
			continue;
		}
		if (c == 'R' || c == 'G') {//R이나 G가 보이는 경우
			if (gp->pic[y + p][x + q] == 'B') {//B인 경우
				continue;
			}
		}
		else if (c == 'B') {//B이 보이는 경우
			if (gp->pic[y+p][x+q] == 'R' || gp->pic[y+p][x+q] == 'G') {//R이나 G인 경우
				continue;
			}
		}
		abnormaldfs(x + q, y + p, c);
	}
}

void init() {
	int i,j;
	char* str;
	gp = (picture*)malloc(sizeof(picture));
	scanf("%d", &gp->n);
	gp->pic = (char**)malloc(gp->n * sizeof(char*));
	gp->visited = (int**)malloc(gp->n * sizeof(int*));
	str = (char*)malloc(((gp->n) + 1) * sizeof(char));
	for (i = 0; i < gp->n; i++) {
		gp->pic[i] = (char*)malloc((gp->n + 1) * sizeof(char));
		gp->visited[i] = (int*)calloc(gp->n , sizeof(int));
		scanf("%s", str);
		for (j = 0; j < gp->n; j++) {
			gp->pic[i][j] = str[j];
		}
	}
	gp->count = 0;
	free(str);
}

void finish() {
	int i;
	for (i = 0; i < gp->n; i++) {
		free(gp->pic[i]);
		free(gp->visited[i]);
	}
	free(gp->pic);
	free(gp->visited);
	free(gp);
}