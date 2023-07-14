#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int person;//사람 번호
	struct node* next;//간선으로 이어져 있는 노드
	int isVisited;//방문 여부 0 : 없음 1: 있음
	int count;//촌수
}node;

typedef struct graph_pointer {
	int vn;//vertex
	int en;//edge
	node* graph;//그래프
	int parent;//조상(자식과의 촌수 계산)
	int child;//자식(조상과의 촌수 계산)
}graph_pointer;

void init();
//동적 배열 할당 및 입력
void insertEdge(int, int);
//간선 형성
void dfs(int);
//dfs를 통해 입력된 수를 기준으로 촌수 계산
void finish();
//동적 해제


graph_pointer* gp;

int main() {
	init();
	dfs(gp->parent);
	if (gp->graph[(gp->child)-1].count == 0) {//촌수 계산 불가
		printf("-1");
	}
	else {
		printf("%d", gp->graph[(gp->child)-1].count);
	}
	finish();
}


void dfs(int v) {
	node* w;
	gp->graph[v - 1].isVisited = 1;//방문했음을 표시
	for (w = gp->graph[v - 1].next; w; w = w->next) {//연결되어 있는 모든 경우에 대해
		if (gp->graph[(w->person)-1].isVisited == 0) {//방문하지 않았다면
			gp->graph[(w->person) - 1].count = (gp->graph[v - 1].count) + 1;//촌수를 1늘려서 저장
			
			dfs(w->person);//dfs실시
		}
	}
}

void init() {
	int i,x,y;
	gp = (graph_pointer*)malloc(sizeof(graph_pointer));
	scanf("%d", &gp->vn);
	gp->graph = (node*)malloc((gp->vn) * sizeof(node));
	for (i = 0; i < gp->vn; i++) {
		gp->graph[i].person = i + 1;
		gp->graph[i].next = NULL;
		gp->graph[i].isVisited = 0;
		gp->graph[i].count = 0;
	}
	scanf("%d %d", &gp->child, &gp->parent);
	scanf("%d", &gp->en);
	for (i = 0; i < gp->en; i++) {
		scanf("%d %d", &x, &y);
		insertEdge(x, y);
	}
}

void insertEdge(int x, int y) {
	node* w;
	node* tmp;
	w = (node*)malloc(sizeof(node));
	w->person = x;
	w->next = NULL;
	tmp = gp->graph[y - 1].next;
	if (tmp == NULL) {
		gp->graph[y - 1].next = w;
	}
	else {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = w;
	}
	w = (node*)malloc(sizeof(node));
	w->person = y;
	w->next = NULL;
	tmp = gp->graph[x - 1].next;
	if (tmp == NULL) {
		gp->graph[x - 1].next = w;
	}
	else {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = w;
	}
}

void finish() {
	int i;
	node* tmp;
	node* w;
	for (i = 0; i < gp->vn; i++) {
		w = gp->graph[i].next;
		if (w != NULL) {
			tmp = w;
			w = w->next;
			free(tmp);
		}
	}
	free(gp->graph);
	free(gp);
}