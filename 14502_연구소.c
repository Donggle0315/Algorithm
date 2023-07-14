#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int row;
	int col;
	int** map;//입력받은 지도
	int** copy;//원래의 지도를 복사한 뒤, 선택된 벽 3개를 추가한 지도
	int** visited;//방문 여부
}graph;

typedef struct node {
	int r;//행
	int c;//열
}node;

/*초기 설정 및 종료 함수*/
void init();
//동적 배열 할당 및 입력
void finish();
//동적 해제

/*안전구역을 찾는 함수*/
int bfs(int,int);
//bfs를 통해 바이러스를 퍼뜨림. 바이러스가 퍼진 영역의 개수를 반환
int findSafeZone();
//빈 방(0)중 3개를 선택하여 복사된 지도에 벽을 세운 뒤, 해당 지도를 기준으로 바이러스가 있는 곳에 대해 bfs실시. 바이러스가 가장 적게 나온 경우에서 안전구역 개수 반환
void makeCopyMap();
//gp->copy에 gp->map을 복사
void deleteCopy();
//동적할당된 gp->copy를 동적 해제하고, 다음 실행을 위한 변수들 초기화


/*큐 관련 함수*/
void addq(int, int);
//큐 add(행, 렬)
void deleteq(node*);
//큐 delete(node에 정보 저장)
int empty();
//큐가 비었다면 1, 아니면 0 반환


graph* gp;
node queue[64];
front = 0;
rear = 0;

node* virus;//바이러스의 위치 정보 저장
int vc;//바이러스의 개수
node* blank;//빈방의 위치 정보 저장
int bc;//빈방의 개수
int wc;//벽의 개수
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//상하좌우 방향 정보

int main() {
	init();
	printf("%d", findSafeZone());
	finish();

	return 0;
}


int findSafeZone() {
	int i, j, k,l;
	int count,min=64;
	for (i = 0; i < bc-2; i++) {
		for (j = i+1; j < bc-1; j++) {
			for (k = j + 1; k < bc; k++) {//bc(빈방의 개수)중 3개를 선택
				makeCopyMap();//기존의 지도를 gp->copy에 복사
				count = 0;//바이러스의 개수
				gp->copy[blank[i].r][blank[i].c]=1;
				gp->copy[blank[j].r][blank[j].c] = 1;
				gp->copy[blank[k].r][blank[k].c] = 1;//gp->copy에 벽 3개를 세운다
				for (l = 0; l < vc; l++) {//바이러스 개수만큼
					count+=bfs(virus[l].r,virus[l].c);//bfs로 바이러스를 퍼뜨리고, 퍼진 바이러스 개수 저장
				}
				if (count < min) {//바이러스가 가장 작은 경우를 min에 저장
					min = count;
				}
				deleteCopy();//다음 탐색을 위한 초기화
			}
		}
	}
	return (gp->row*gp->col-wc-3)-min;//전체 지도의 넓이 - 벽의 개수 - 새로 만든 벽 3개 - 최소한의 바이러스 수
}

int bfs(int r,int c) {//bfs로 바이러스를 퍼뜨림
	int i,p,q;
	int count = 0;//바이러스의 개수
	node* w=(node*)malloc(sizeof(node));
	gp->visited[r][c] = 1;
	count++;
	addq(r, c);
	while (empty() == 0) {
		deleteq(w);
		for (i = 0; i < 4; i++) {//상하좌우 방향에 대해
			p = w->r + dir[i][0];
			q = w->c + dir[i][1];
			if (p < 0 || p >= gp->row) {//범위 밖
				continue;
			}
			if (q < 0 || q >= gp->col) {//범위 밖
				continue;
			}
			if (gp->visited[p][q] == 1) {//방문했다면
				continue;
			}
			if (gp->copy[p][q] != 0) {//빈방이 아니라면
				continue;
			}
			addq(p, q);
			count++;//바이러스가 1개 늘어남
			gp->copy[p][q] = 2;//해당 방 바이러스로 바뀜
			gp->visited[p][q] = 1;//방문
		}
	}
	free(w);
	return count;//총 바이러스 개수 반환
}

void makeCopyMap() {//지도 복사
	int i, j;
	gp->copy = (int**)malloc(gp->row * sizeof(int*));
	for (i = 0; i < gp->row; i++) {
		gp->copy[i] = (int*)malloc(gp->col * sizeof(int));
		for (j = 0; j < gp->col; j++) {
			gp->copy[i][j] = gp->map[i][j];
			gp->visited[i][j] = 0;
		}
	}
}

void deleteCopy() {
	int i;
	for (i = 0; i < gp->row; i++) {
		free(gp->copy[i]);
	}
	free(gp->copy);
	front = 0;
	rear = 0;//큐 초기화
}

void addq(int r, int c) {
	queue[front].r = r;
	queue[front++].c = c;
}

void deleteq(node* w) {
	w->r = queue[rear].r;
	w->c = queue[rear++].c;
}

int empty() {
	if (rear == front) {
		return 1;
	}
	return 0;
}

void init() {
	int i, j;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d", &gp->row, &gp->col);

	virus = (node*)malloc(gp->row * gp->col * sizeof(node));
	vc = 0;
	blank = (node*)malloc(gp->row * gp->col * sizeof(node));
	bc = 0;

	gp->map = (int**)malloc(gp->row * sizeof(int*));
	gp->visited = (int**)malloc(gp->row * sizeof(int*));
	
	for (i = 0; i < gp->row; i++) {
		gp->map[i] = (int*)malloc(gp->col * sizeof(int));
		gp->visited[i] = (int*)calloc(gp->col, sizeof(int));
		for (j = 0; j < gp->col; j++) {
			scanf("%d", &gp->map[i][j]);
			if (gp->map[i][j] == 2) {//해당 칸이 바이러스라면
				virus[vc].r = i;
				virus[vc++].c = j;
			}
			else if (gp->map[i][j] == 0) {//해당 칸이 빈방이라면
				blank[bc].r = i;
				blank[bc++].c = j;
			}
			else {//해당 칸이 벽이라면
				wc++;
			}
		}
	}
}

void finish() {
	int i;
	for (i = 0; i < gp->row; i++) {
		free(gp->map[i]);
		free(gp->visited[i]);
	}
	free(gp->map);
	free(gp->visited);
	free(gp);
	free(virus);
	free(blank);
}