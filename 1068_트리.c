#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int name;//노드의 번호
	struct node* child;//노드의 자식 노드의 주소를 연결리스트로 저장
	int childNum;//노드의 자식 수
}node;

typedef struct tree_pointer {
	int n;//트리의 노드의 개수
	node* tree;//트리
	node* root;//루트 노드를 저장
	int dn;//삭제할 노드의 번호
}tree_pointer;

tree_pointer* tp;
int* parent;

void init();
//동적 할당 및 입력, 트리 생성
void insertChild(int, int);
//자식 노드와 부모 노드를 연결
int deleteChild();
//지워진 tp->dn이 유일한 자식이면 부모 노드는 리프 노드가 됨
int findLeafNode(int);
//리프 노드의 개수 반환, tp->dn을 만나면 더이상 탐색하지 않음
void finish();
//동적 해제

int main() {
	init();
	printf("%d", findLeafNode(tp->root->name)+ deleteChild());
	finish();

	return 0;
}

int deleteChild() {
	int p = parent[tp->dn];
	if (tp->tree[p].childNum == 1) {//tp->dn의 부모노드의 자식이 dn이 유일하면
		return 1;//부모노드는 리프 노드가 됨
	}
	else {
		return 0;//부모 노드는 리프 노드가 아님
	}

}

int findLeafNode(int v) {
	node* w = &(tp->tree[v]);//v번째 노드에 대해서 조사
	int count = 0;//리프 노드에 개수
	if (w->name == tp->dn) {//삭제할 노드라면
		return 0;
	}
	if (w->child== NULL) {//자식이 없는 리프 노드라면
		return 1;
	}
	
	else {//자식이 있는 부모 노드라면
		while (w->child != NULL) {//모든 자식 노드에 대해
			w = w->child;
			count += findLeafNode(w->name);//재귀 함수 실행
		}
	}
	return count;//리프 노드의 값 반환
}

void finish() {
	node* tmp;
	node* w;
	int i;
	for (i = 0; i < tp->n; i++) {
		w = tp->tree[i].child;
		while (w != NULL) {
			tmp = w;
			w = w->child;
			free(tmp);
		}
	}
	free(tp->tree);
	free(tp);
	free(parent);
}

void init() {
	int i;
	tp = (tree_pointer*)malloc(sizeof(tree_pointer));
	scanf("%d", &tp->n);
	tp->tree = (node*)malloc(tp->n * sizeof(node));
	parent = (int*)malloc(tp->n * sizeof(int));
	for (i = 0; i < tp->n; i++) {
		tp->tree[i].name = i;
		tp->tree[i].child = NULL;
		tp->tree[i].childNum = 0;
	}
	for (i = 0; i < tp->n; i++) {
		scanf("%d ", &parent[i]);
		insertChild(i, parent[i]);
	}
	scanf("%d", &tp->dn);
}

void insertChild(int c, int p) {
	node* tmp;
	node* w;
	
	if (p == -1) {
		tp->root = &(tp->tree[c]);
		return;
	}
	tmp=&(tp->tree[p]);
	w = (node*)malloc(sizeof(node));
	w->name = c;
	w->child = NULL;
	w->childNum = 0;
	while (tmp->child != NULL) {
		tmp = tmp->child;
	}
	tmp->child = w;
	tp->tree[p].childNum++;
}