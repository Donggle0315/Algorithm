#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
}node;

void init();
//���� �Ҵ� �� �Է�, Ʈ�� ����
void preorderTraversal(node*);
//���� ��ȸ ���
void inorderTraversal(node*);
//���� ��ȸ ���
void postorderTraversal(node*);
//���� ��ȸ ���
void finish();
//���� ����

node* list;

int main() {
	init();
	preorderTraversal(&list[0]);
	printf("\n");
	inorderTraversal(&list[0]);
	printf("\n");
	postorderTraversal(&list[0]);
	finish();

	return 0;
}

void preorderTraversal(node* n) {
	if (n == NULL) {
		return;
	}
	printf("%c", n->data);
	preorderTraversal(n->left);
	preorderTraversal(n->right);
}

void inorderTraversal(node* n) {
	if (n == NULL) {
		return;
	}
	inorderTraversal(n->left);
	printf("%c", n->data);
	inorderTraversal(n->right);
}

void postorderTraversal(node* n) {
	if (n == NULL) {
		return;
	}
	postorderTraversal(n->left);
	postorderTraversal(n->right);
	printf("%c", n->data);
}

void init() {
	int n,i;
	char c, l, r;
	scanf("%d", &n);
	list = (node*)malloc(n * sizeof(node));
	for (i = 0; i < n; i++) {
		scanf(" %c %c %c", &c, &l, &r);
		list[c - 'A'].data = c;//���ĺ� ������ �´� ��ġ�� ����
		if (l != '.') {
			list[c - 'A'].left = &list[l - 'A'];
		}
		else {
			list[c - 'A'].left = NULL;
		}
		if (r != '.') {
			list[c - 'A'].right = &list[r - 'A'];
		}
		else {
			list[c - 'A'].right = NULL;
		}
	}
}

void finish() {
	free(list);
}