#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;//��ȣ
	struct node* next;//����Ǿ� �ִ� ���
}node;

typedef struct graph_pointer {
	int vn;//vertex ����
	int en;//edge ����
	int* visited;//�湮 ���� ǥ�� 0 ���� 1 ����
	node* graph;//�׷���
}graph_pointer;

void init();
//�����迭�Ҵ� �� �Է�
void finish();
//���� ����
void dfs(int);
//dfs������� �湮
int countOfCC();
//�������� ���� ��ȯ
void insertEdge(int,int);
//edge�� ������

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
		insertEdge(a, b);//������ ����
	}
}

void finish() {
	free(gp->graph);
	free(gp->visited);
	free(gp);
}

void dfs(int v) {
	node* w;
	gp->visited[v - 1] = 1;//�湮�Ͽ��ٰ� ǥ��
	for (w = &(gp->graph[v - 1]); w; w = w->next) {//edge�� ����
		if (gp->visited[(w->num) - 1] == 0) {//�湮���� �ʾҴٸ�
			dfs(w->num);//dfs�ǽ�
		}
	}
}

int countOfCC() {
	int count = 0;
	int i;
	for (i = 0; i < gp->vn; i++) {
		if (gp->visited[i] == 0) {//�湮���� �ʾҴٸ�
			dfs(i+1);
			count++;//������ ���� +1
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