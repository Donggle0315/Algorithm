#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int name;
	struct node* left;//name���� ���� ���� ���� �ڽ� ���
	struct node* right;//name���� ū ���� ���� �ڽ� ���
}node;

node* root;//��Ʈ ���
node* cur;//���� ����Ű�� ���

void init();
//���� �Ҵ� �� �Է�, Ʈ�� ����
void makeRoot(int);
//��Ʈ ��� ����
void makeChild(int);
//��� ����
void postTraversal(node*);
//���� ��ȸ�� ��� ���
void deleteNode(node*);
//Ʈ���� ��带 ���� ��ȸ�� ���� ����
void finish();
//���� ����


int main() {
	init();
	postTraversal(root);
	finish();

	return 0;
}

void init() {
	int count = 0,n;
	while (scanf("%d", &n) != EOF) {
		if (count == 0) {//ó�� �޴� �Է��̸�
			makeRoot(n);//��Ʈ ��� ����
		}
		else {
			makeChild(n);//��� ����
		}
		count++;
	}
}

void finish() {
	deleteNode(root);
}

void deleteNode(node* c) {
	if (c == NULL) {
		return;
	}
	deleteNode(c->left);
	deleteNode(c->right);
	free(c);
}

void makeRoot(int v) {
	root = (node*)malloc(sizeof(node));//��Ʈ �����Ϳ� ���� �Ҵ�
	root->name = v;
	root->left = NULL;
	root->right = NULL;
	cur = root;
}

void makeChild(int v) {
	node* w = (node*)malloc(sizeof(node));
	node* before;
	w->name = v;
	w->left = NULL;
	w->right = NULL;
	cur = root;
	before = root;//cur�� �θ��带 ����Ŵ
	while (cur != NULL) {//���ڸ��� ���� �� ����
		before = cur;
		if (cur->name > w->name) {//���� ����� ������ ���� ���̶��
			cur = cur->left;//���� ����
		}
		else {//���� ����� ������ ū ���̶��
			cur = cur->right;//������ ����
		}
	}
	if (before->name < w->name) {
		before->right = w;//�� ���� ��� ����
	}
	else {
		before->left = w;//�� ���� ��� ����
	}

}

void postTraversal(node* c) {
	if (c == NULL) {
		return;
	}
	postTraversal(c->left);//���� �ڽ� Ž��
	postTraversal(c->right);//������ �ڽ� Ž��
	printf("%d\n", c->name);//���� ����� �� ���
}