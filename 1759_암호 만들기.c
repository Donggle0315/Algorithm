#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void init();
//�Է� �� �Է¹��� ���ĺ��� ������������ ����
void backtracking(int,int);
//��Ʈ��ŷ�� ����Ͽ� ��ȣ�� ����. ���ǿ� ������ ���
void quicksort(int, int);
//�� ����
void print();
//�ּ� ������ ������ 1��, ������ ���� 2���� �����ϸ� ���

int l, c;
char code[15];//��ȣ����
char list[15];//�Է¹��� ���ĺ� ����
int consonant;//������ ����
int  vowel;//������ ����

int main() {
	init();
	backtracking(-1, 0);

	return 0;
}

void backtracking(int start,int depth) {
	int i;
	if (depth == l) {//��ȣ�� �� ä���ٸ�
		print();//���ǿ� �´ٸ� ���
		return;
	}
	for (i = start+1; i < c; i++) {//������������ ���ĵ� ���ĺ��� ����
		if (list[i] == 'a' || list[i] == 'e' || list[i] == 'i'||list[i] == 'o' || list[i] == 'u') {
			vowel++;//����
		}
		else {
			consonant++;//����
		}
		code[depth] = list[i];//��ȣ�� �Է�
		backtracking(i, depth + 1);//���� ���� ����
		if (list[i] == 'a' || list[i] == 'e' || list[i] == 'i' || list[i] == 'o' || list[i] == 'u') {
			vowel--;//���� ����
		}
		else {
			consonant--;//���� ����
		}
	}
}

void print() {
	int i;
	if(consonant<2||vowel<1){//���� 2�� Ȥ�� ���� 1�� �̸��̶��
		return;//������� ����
	}
	for (i = 0; i < l; i++) {//���
		printf("%c", code[i]);
	}
	printf("\n");
}

void init() {
	int i;
	scanf("%d %d", &l, &c);
	for (i = 0; i < c; i++) {
		scanf(" %c", &list[i]);
	}
	quicksort(0, c - 1);
	consonant = 0;
	vowel = 0;
}

void quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	char x =list[(left + right) / 2];
	char tmp;
	do {
		while (list[pl] < x) {
			pl++;
		}
		while (x < list[pr]) {
			pr--;
		}
		if (pl <= pr) {
			tmp = list[pl];
			list[pl] = list[pr];
			list[pr] = tmp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		quicksort(left, pr);
	}
	if (pl < right) {
		quicksort(pl, right);
	}
}