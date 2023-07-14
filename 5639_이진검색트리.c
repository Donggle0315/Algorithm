#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int name;
	struct node* left;//name보다 작은 값을 갖는 자식 노드
	struct node* right;//name보다 큰 값을 갖는 자식 노드
}node;

node* root;//루트 노드
node* cur;//현재 가리키는 노드

void init();
//동적 할당 및 입력, 트리 생성
void makeRoot(int);
//루트 노드 생성
void makeChild(int);
//노드 생성
void postTraversal(node*);
//후위 순회한 결과 출력
void deleteNode(node*);
//트리의 노드를 후위 순회로 동적 해제
void finish();
//동적 해제


int main() {
	init();
	postTraversal(root);
	finish();

	return 0;
}

void init() {
	int count = 0,n;
	while (scanf("%d", &n) != EOF) {
		if (count == 0) {//처음 받는 입력이면
			makeRoot(n);//루트 노드 생성
		}
		else {
			makeChild(n);//노드 생성
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
	root = (node*)malloc(sizeof(node));//루트 포인터에 동적 할당
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
	before = root;//cur의 부모노드를 가리킴
	while (cur != NULL) {//빈자리가 있을 때 까지
		before = cur;
		if (cur->name > w->name) {//현재 노드의 값보다 작은 값이라면
			cur = cur->left;//왼쪽 노드로
		}
		else {//현재 노드의 값보다 큰 값이라면
			cur = cur->right;//오른쪽 노드로
		}
	}
	if (before->name < w->name) {
		before->right = w;//빈 곳에 노드 삽입
	}
	else {
		before->left = w;//빈 곳에 노드 삽입
	}

}

void postTraversal(node* c) {
	if (c == NULL) {
		return;
	}
	postTraversal(c->left);//왼쪽 자식 탐색
	postTraversal(c->right);//오른쪽 자식 탐색
	printf("%d\n", c->name);//현재 노드의 값 출력
}