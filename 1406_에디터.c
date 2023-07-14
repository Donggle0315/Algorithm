#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
	char data; //����
	struct linkedList* next;//���� ���Ҹ� ����Ű�� ������
	struct linkedList* prev;//���� ���Ҹ� ����Ű�� ������
}linkedList;//���ڿ� ���� ������ ��� �ִ� ����ü

typedef struct pList {
	struct linkedList* head;//�� �տ� �ִ� ���� ��带 ����Ŵ
	struct linkedList* cur;//���� ��ġ�� ǥ���ϴ� �����ͷ� Ŀ���� ����Ŵ. ���ڿ��� �ش� ����� �����ʰ� ���� ����� ���ʿ� Ŀ���� ������.
}pList;//���Ḯ��Ʈ�� ���� ������ ��� �ִ� ����ü

void init();//�ʱ�ȭ�ϴ� �Լ��� ���Ḯ��Ʈ�� �����ϰ�, �ʱ⿡ �����Ǿ� �ִ� ���ڿ��� ���Ḯ��Ʈ�� �����Ѵ�.
void finish();//���� �迭 ����
linkedList* elementInit(char data);//��带 �����Ѵ�.
void moveCursorLeft();//Ŀ���� �������� �̵��Ѵ�.
void moveCursorRight();//Ŀ���� ���������� �̵��Ѵ�.
void backspace();//Ŀ�� ���� ���ڸ� �����Ѵ�.
void insert(char data);//Ŀ�� ���ʿ� data�� �����Ѵ�.
void printing();//�迭����Ʈ ��ü ���Ҹ� ������� ����Ѵ�.
void command();//Ŀ�ǵ��� Ƚ���� Ŀ�ǵ带 �Է¹ް�, �Է¿� ���� �Լ��� �����Ѵ�.


pList* pl;

int main() {
	init();
	command();
	printing();
	finish();

	return 0;
}


void init() {
	int i;
	char str[100001];//�ʱ⿡ �����⿡ �ԷµǾ� �ִ� ���ڿ�
	pl = (pList*)malloc(sizeof(pList));
	linkedList* dumi = elementInit(0);//���� ��带 �����ؼ� Ŀ��Ȱ���� ���ܸ� ����
	pl->cur =dumi;
	pl->head = dumi;
	scanf("%s ", str);
	for (i = 0; str[i] != '\0'; i++) {
		insert(str[i]);
	}
}

void finish() {
	linkedList* next;
	for (pl->cur = pl->head; pl->cur != NULL; ) {
		next = pl->cur->next;
		free(pl->cur);
		pl->cur = next;
	}
	free(pl);
}

linkedList* elementInit(char data) {
	linkedList* new_data = (linkedList*)malloc(sizeof(linkedList));
	new_data->data = data;
	new_data->prev = NULL;
	new_data->next = NULL;
	return new_data;
}

void insert(char data) {//Ŀ���� ����Ű�� ��� �����ʿ� ������.
	linkedList* element = elementInit(data);
	element->prev = pl->cur;
	element->next = pl->cur->next;
	if (element->next != NULL) {//���� �������̶� ���� ��尡 ���� ���
		element->next->prev = element;
	}
	pl->cur->next = element;
	pl->cur = element;//Ŀ���� ���� ���� �̵�
}

void backspace() {
	linkedList* tmp;
	if (pl->cur == pl->head) {//Ŀ���� ���� ��带 ����ų ��� Ŀ�� ���ʿ� ��尡 ����
		return;
	}
	tmp = pl->cur;
	pl->cur = pl->cur->prev;
	pl->cur->next = tmp->next;
	if (tmp->next != NULL) {//Ŀ���� ���� ������ ��尡 �ƴ� ���
		tmp->next->prev = pl->cur;
	}
	free(tmp);
}

void moveCursorLeft() {
	if (pl->cur->prev == NULL) {//Ŀ���� �� ���ʿ� ���� ���
		return;
	}
	pl->cur = pl->cur->prev;//Ŀ���� �������� �̵�
}

void moveCursorRight() {
	if (pl->cur->next == NULL) {//Ŀ���� �� �����ʿ� ���� ���
		return;
	}
	pl->cur = pl->cur->next;//Ŀ���� ���������� �̵�
}

void command() {
	int i, num;
	char com, data;
	scanf("%d ", &num);//�Է¹��� Ŀ�ǵ� ����
	for (i = 0; i < num; i++) {
		scanf(" %c", &com);
		switch(com) {
			case 'L'://�������� �̵�
				moveCursorLeft();
				break;
			case 'D'://���������� �̵�
				moveCursorRight();
				break;
			case 'B'://���� ����
				backspace();
				break;
			case 'P'://���� �߰�
				scanf(" %c", &data);
				insert(data);
				break;
		}
	}
}


void printing() {
	linkedList* tmp = pl->head->next;
	for (; tmp != NULL; tmp = tmp->next) {
		printf("%c", tmp->data);
	}
}


