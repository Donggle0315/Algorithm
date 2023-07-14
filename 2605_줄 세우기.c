#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
	int student; //n번째 학생
	struct linkedList* next;//앞에 있는 학생을 가리킴
}linkedList;//학생에 대한 정보를 담고 있는 구조체

typedef struct pList {
	struct linkedList* head;//젤 마지막에 있는 학생을 가리킴
	struct linkedList* cur;//현재 위치를 표시하는 포인터로 포인터 앞으로 학생을 삽입
	int numoflist;//현재 줄 서 있는 학생의 수
}pList;//연결리스트에 대한 정보를 담고 있는 구조체

void init();
//pList 구조체에 대한 동적 할당 및 몇 명의 학생을 줄 세울지 입력 받는다.
linkedList* elementInit(int);
//학생 한명의 정보를 표시할 노드를 동적할당하여 생성하고 해당 주소를 반환한다.
void finish();
//동적 할당 해제
void insert(int);
//입력 받은 수만큼 학생을 앞으로 보낸 뒤, 해당 위치에 노드를 삽입한다.
void printing();
//줄의 첫번째부터 차례대로 학생 번호를 출력한다.


int num; //총 학생 수
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
	scanf("%d", &data);//앞으로 이동할 횟수
	if (data == 0) {//이동할 필요 없어 맨 뒤(head가 가리키는 곳)에 서야함
		if (pl->head != NULL) {//연결리스트에 원소가 있을 때
			element->next = pl->head;//
		}
		pl->head = element;
	}
	else {//앞으로 이동해야함
		pl->cur = pl->head;//cur이 가리키는 원소 앞으로 삽입
		for (i = 1; i < data; i++) {
			pl->cur = pl->cur->next;//cur 이동
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
	}//head 포인터가 젤 뒤를 가리키므로 앞으로 오면서 학생 정보를 리스트에 저장
	for (i = pl->numoflist - 1; i >= 0; i--) {
		printf("%d ", list[i]);//역순을 출력하면 앞에서 뒤로
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