#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;//번호
	struct node* next;//연결되어 있는 노드
}node;

typedef struct graph_pointer {
	int vn;//vertex 개수
	int en;//edge 개수
	int* visited;//방문 여부 표시 0 없음 1 있음
	node* graph;//그래프
}graph_pointer;

void init();
//동적배열할당 및 입력
void finish();
//동적 해제
void dfs(int);
//dfs방법으로 방문
int countOfCC();
//연결요소의 개수 반환
void insertEdge(int,int);
//edge를 삽입함

graph_pointer* gp;

int main() {
	init();
	printf("%d", countOfCC());
	finish();
}

void init() {
	int a, b,i;
	gp = (graph_pointer*)malloc(sizeof(graph_pointer));
	scanf("%d %d", &gp->vn, &gp->en);
	gp->graph = (node*)malloc(gp->vn * sizeof(node));
	for (i = 0; i < gp->vn; i++) {
		gp->graph[i].num = i + 1;
		gp->graph[i].next = NULL;
	}
	gp->visited = (int*)calloc(gp->vn,sizeof(int));
	for (i = 0; i < gp->en; i++) {
		scanf(" %d %d", &a, &b);
		insertEdge(a, b);//연결요소 삽입
	}
}

void finish() {
	free(gp->graph);
	free(gp->visited);
	free(gp);
}

void dfs(int v) {
	node* w;
	gp->visited[v - 1] = 1;//방문하였다고 표시
	for (w = &(gp->graph[v - 1]); w; w = w->next) {//edge를 따라서
		if (gp->visited[(w->num) - 1] == 0) {//방문하지 않았다면
			dfs(w->num);//dfs실시
		}
	}
}

int countOfCC() {
	int count = 0;
	int i;
	for (i = 0; i < gp->vn; i++) {
		if (gp->visited[i] == 0) {//방문하지 않았다면
			dfs(i+1);
			count++;//연결요소 개수 +1
		}
	}
	return count;
}

void insertEdge(int a, int b) {
	node* np;
	node* tmp = (node*)malloc(sizeof(node));
	tmp->num = b;
	tmp->next = NULL;
	np = gp->graph[a - 1].next;
	if (np == NULL) {
		gp->graph[a - 1].next = tmp;
	}
	else {
		tmp->next = np;
		gp->graph[a - 1].next = tmp;
	}
	tmp = (node*)malloc(sizeof(node));
	tmp->num =a;
	tmp->next = NULL;
	np = gp->graph[b - 1].next;
	if (np == NULL) {
		gp->graph[b - 1].next = tmp;
	}
	else {
		tmp->next = np;
		gp->graph[b - 1].next = tmp;
	}
}