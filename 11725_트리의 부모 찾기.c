#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//연결리스트로 풀기. 배열로 풀면 메모리 초과

typedef struct node {
	int num;
	struct node* next;
}node;

typedef struct tree_pointer {
	int n;
	node* tree;
	int* visited;
	int* parent;
}tree_pointer;

void init();
void insertEdge(int, int);//노드 간 관계를 연결
void findParent(int);//해당 노드의 부모 노드를 찾아 parent 배열에 저장
void printing();
void finish();

tree_pointer* tp;

int main() {
	init();
	findParent(1);
	printing();
	finish();

	return 0;
}

void init() {
	int i, a, b;
	tp = (tree_pointer*)malloc(sizeof(tree_pointer));
	scanf("%d", &tp->n);
	tp->tree = (node*)malloc(tp->n * sizeof(node));
	for (i = 0; i < tp->n; i++) {
		tp->tree[i].num =i+1;
		tp->tree[i].next = NULL;
	}
	tp->visited = (int*)calloc(tp->n , sizeof(int));
	tp->parent = (int*)calloc(tp->n, sizeof(int));

	for (i = 0; i < tp->n - 1; i++) {
		scanf("%d %d", &a, &b);
		insertEdge(a,b);
	}

}

void insertEdge(int a, int b) {
	node* w;
	node* tmp;
	w = (node*)malloc(sizeof(node));
	w->num = b;
	w->next = NULL;
	tmp=&(tp->tree[a - 1]);
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp -> next = w;
	w = (node*)malloc(sizeof(node));
	w->num = a;
	w->next = NULL;
	tmp = &(tp->tree[b - 1]);
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = w;
}

void findParent(int v) {//dfs 기반 탐색
	node* w=&(tp->tree[v-1]);//1부터 시작
	tp->visited[v-1] = 1;
	while (w != NULL) {
		if (tp->visited[w->num - 1] == 0) {//자식을 찾으면
			tp->parent[w->num - 1] = v;//부모노드 번호 저장
			findParent(w->num);//자식의 자식 탐색
		}
		w = w->next;
	}
}


void printing() {
	int i;
	for (i = 1; i < tp->n; i++) {
		printf("%d\n", tp->parent[i]);
	}
}

void finish() {
	int i;
	node* w;
	node* tmp;
	for (i = 0; i < tp->n; i++) {
		w = tp->tree[i].next;
		while (w!= NULL) {
			tmp = w;
			w = w->next;
			free(tmp);
		}
	}
	free(tp->tree);
	free(tp->visited);
	free(tp->parent);
	free(tp);
}