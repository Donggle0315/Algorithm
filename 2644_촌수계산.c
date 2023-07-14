#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int person;//��� ��ȣ
	struct node* next;//�������� �̾��� �ִ� ���
	int isVisited;//�湮 ���� 0 : ���� 1: ����
	int count;//�̼�
}node;

typedef struct graph_pointer {
	int vn;//vertex
	int en;//edge
	node* graph;//�׷���
	int parent;//����(�ڽİ��� �̼� ���)
	int child;//�ڽ�(������� �̼� ���)
}graph_pointer;

void init();
//���� �迭 �Ҵ� �� �Է�
void insertEdge(int, int);
//���� ����
void dfs(int);
//dfs�� ���� �Էµ� ���� �������� �̼� ���
void finish();
//���� ����


graph_pointer* gp;

int main() {
	init();
	dfs(gp->parent);
	if (gp->graph[(gp->child)-1].count == 0) {//�̼� ��� �Ұ�
		printf("-1");
	}
	else {
		printf("%d", gp->graph[(gp->child)-1].count);
	}
	finish();
}


void dfs(int v) {
	node* w;
	gp->graph[v - 1].isVisited = 1;//�湮������ ǥ��
	for (w = gp->graph[v - 1].next; w; w = w->next) {//����Ǿ� �ִ� ��� ��쿡 ����
		if (gp->graph[(w->person)-1].isVisited == 0) {//�湮���� �ʾҴٸ�
			gp->graph[(w->person) - 1].count = (gp->graph[v - 1].count) + 1;//�̼��� 1�÷��� ����
			
			dfs(w->person);//dfs�ǽ�
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