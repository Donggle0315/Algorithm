#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
	int student; //n��° �л�
	struct linkedList* next;//�տ� �ִ� �л��� ����Ŵ
}linkedList;//�л��� ���� ������ ��� �ִ� ����ü

typedef struct pList {
	struct linkedList* head;//�� �������� �ִ� �л��� ����Ŵ
	struct linkedList* cur;//���� ��ġ�� ǥ���ϴ� �����ͷ� ������ ������ �л��� ����
	int numoflist;//���� �� �� �ִ� �л��� ��
}pList;//���Ḯ��Ʈ�� ���� ������ ��� �ִ� ����ü

void init();
//pList ����ü�� ���� ���� �Ҵ� �� �� ���� �л��� �� ������ �Է� �޴´�.
linkedList* elementInit(int);
//�л� �Ѹ��� ������ ǥ���� ��带 �����Ҵ��Ͽ� �����ϰ� �ش� �ּҸ� ��ȯ�Ѵ�.
void finish();
//���� �Ҵ� ����
void insert(int);
//�Է� ���� ����ŭ �л��� ������ ���� ��, �ش� ��ġ�� ��带 �����Ѵ�.
void printing();
//���� ù��°���� ���ʴ�� �л� ��ȣ�� ����Ѵ�.


int num; //�� �л� ��
int* list;
pList* pl;

int main() {
	int i;
	init();
	for (i = 1; i <= num; i++) {
		insert(i);
	}
	printing();
	finish();

	return 0;
}

linkedList* elementInit(int studentNum) {
	linkedList* new_data = (linkedList*)malloc(sizeof(linkedList));
	new_data->student = studentNum;
	new_data->next = NULL;
	pl->numoflist++;
	return new_data;
}

void insert(int studentNum) {
	int data,i;
	linkedList* element = elementInit(studentNum);
	scanf("%d", &data);//������ �̵��� Ƚ��
	if (data == 0) {//�̵��� �ʿ� ���� �� ��(head�� ����Ű�� ��)�� ������
		if (pl->head != NULL) {//���Ḯ��Ʈ�� ���Ұ� ���� ��
			element->next = pl->head;//
		}
		pl->head = element;
	}
	else {//������ �̵��ؾ���
		pl->cur = pl->head;//cur�� ����Ű�� ���� ������ ����
		for (i = 1; i < data; i++) {
			pl->cur = pl->cur->next;//cur �̵�
		}
		element->next = pl->cur->next;
		pl->cur->next = element;
	}
}

void printing() {
	int i=0;
	pl->cur = pl->head;
	for (;pl->cur != NULL; pl->cur = pl->cur->next) {
		list[i++]=pl->cur->student;
	}//head �����Ͱ� �� �ڸ� ����Ű�Ƿ� ������ ���鼭 �л� ������ ����Ʈ�� ����
	for (i = pl->numoflist - 1; i >= 0; i--) {
		printf("%d ", list[i]);//������ ����ϸ� �տ��� �ڷ�
	}
}


void init() {
	scanf("%d", &num);
	pl = (pList*)malloc(sizeof(pList));
	pl->cur = NULL;
	pl->head = NULL;
	pl->numoflist = 0;
	list = (int*)malloc(num * sizeof(int));
}

void finish() {
	int i;
	linkedList* next;
	pl->cur = pl->head;
	for (i = 0; i < pl->numoflist; i++) {
		next = pl->cur->next;
		free(pl->cur);
		pl->cur = next;
	}
	free(pl);
	free(list);
}