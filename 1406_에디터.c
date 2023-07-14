#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
	char data; //숫자
	struct linkedList* next;//다음 원소를 가리키는 포인터
	struct linkedList* prev;//이전 원소를 가리키는 포인터
}linkedList;//숫자에 대한 정보를 담고 있는 구조체

typedef struct pList {
	struct linkedList* head;//젤 앞에 있는 더미 노드를 가리킴
	struct linkedList* cur;//현재 위치를 표시하는 포인터로 커서를 가르킴. 문자열상 해당 노드의 오른쪽과 다음 노드의 왼쪽에 커서가 존재함.
}pList;//연결리스트에 대한 정보를 담고 있는 구조체

void init();//초기화하는 함수로 연결리스트를 생성하고, 초기에 편집되어 있는 문자열을 연결리스트에 삽입한다.
void finish();//동적 배열 해제
linkedList* elementInit(char data);//노드를 생성한다.
void moveCursorLeft();//커서를 왼쪽으로 이동한다.
void moveCursorRight();//커서를 오른쪽으로 이동한다.
void backspace();//커서 왼쪽 문자를 삭제한다.
void insert(char data);//커서 왼쪽에 data를 삽입한다.
void printing();//배열리스트 전체 원소를 순서대로 출력한다.
void command();//커맨드의 횟수와 커맨드를 입력받고, 입력에 따른 함수를 실행한다.


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
	char str[100001];//초기에 편집기에 입력되어 있는 문자열
	pl = (pList*)malloc(sizeof(pList));
	linkedList* dumi = elementInit(0);//더미 노드를 선언해서 커서활용의 예외를 줄임
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

void insert(char data) {//커서가 가리키는 노드 오른쪽에 삽입함.
	linkedList* element = elementInit(data);
	element->prev = pl->cur;
	element->next = pl->cur->next;
	if (element->next != NULL) {//가장 오른쪽이라 다음 노드가 없을 경우
		element->next->prev = element;
	}
	pl->cur->next = element;
	pl->cur = element;//커서를 다음 노드로 이동
}

void backspace() {
	linkedList* tmp;
	if (pl->cur == pl->head) {//커서가 더미 노드를 가르킬 경우 커서 왼쪽에 노드가 없음
		return;
	}
	tmp = pl->cur;
	pl->cur = pl->cur->prev;
	pl->cur->next = tmp->next;
	if (tmp->next != NULL) {//커서가 가장 마지막 노드가 아닐 경우
		tmp->next->prev = pl->cur;
	}
	free(tmp);
}

void moveCursorLeft() {
	if (pl->cur->prev == NULL) {//커서가 젤 왼쪽에 있을 경우
		return;
	}
	pl->cur = pl->cur->prev;//커서를 왼쪽으로 이동
}

void moveCursorRight() {
	if (pl->cur->next == NULL) {//커서가 젤 오른쪽에 있을 경우
		return;
	}
	pl->cur = pl->cur->next;//커서를 오른쪽으로 이동
}

void command() {
	int i, num;
	char com, data;
	scanf("%d ", &num);//입력받을 커맨드 개수
	for (i = 0; i < num; i++) {
		scanf(" %c", &com);
		switch(com) {
			case 'L'://왼쪽으로 이동
				moveCursorLeft();
				break;
			case 'D'://오른쪽으로 이동
				moveCursorRight();
				break;
			case 'B'://문자 삭제
				backspace();
				break;
			case 'P'://문자 추가
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


