#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int name;//����� ��ȣ
	struct node* child;//����� �ڽ� ����� �ּҸ� ���Ḯ��Ʈ�� ����
	int childNum;//����� �ڽ� ��
}node;

typedef struct tree_pointer {
	int n;//Ʈ���� ����� ����
	node* tree;//Ʈ��
	node* root;//��Ʈ ��带 ����
	int dn;//������ ����� ��ȣ
}tree_pointer;

tree_pointer* tp;
int* parent;

void init();
//���� �Ҵ� �� �Է�, Ʈ�� ����
void insertChild(int, int);
//�ڽ� ���� �θ� ��带 ����
int deleteChild();
//������ tp->dn�� ������ �ڽ��̸� �θ� ���� ���� ��尡 ��
int findLeafNode(int);
//���� ����� ���� ��ȯ, tp->dn�� ������ ���̻� Ž������ ����
void finish();
//���� ����

int main() {
	init();
	printf("%d", findLeafNode(tp->root->name)+ deleteChild());
	finish();

	return 0;
}

int deleteChild() {
	int p = parent[tp->dn];
	if (tp->tree[p].childNum == 1) {//tp->dn�� �θ����� �ڽ��� dn�� �����ϸ�
		return 1;//�θ���� ���� ��尡 ��
	}
	else {
		return 0;//�θ� ���� ���� ��尡 �ƴ�
	}

}

int findLeafNode(int v) {
	node* w = &(tp->tree[v]);//v��° ��忡 ���ؼ� ����
	int count = 0;//���� ��忡 ����
	if (w->name == tp->dn) {//������ �����
		return 0;
	}
	if (w->child== NULL) {//�ڽ��� ���� ���� �����
		return 1;
	}
	
	else {//�ڽ��� �ִ� �θ� �����
		while (w->child != NULL) {//��� �ڽ� ��忡 ����
			w = w->child;
			count += findLeafNode(w->name);//��� �Լ� ����
		}
	}
	return count;//���� ����� �� ��ȯ
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