#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
int probability();
void appendA();
void reverseAppendB();
int isEqual();
void cal();

char s[1000];
int lens;
char t[1000];
int lent;


int main() {
	init();
	cal();

	return 0;
}

void init() {
	int i;
	char* str = (char*)malloc(1001 * sizeof(char));
	lens = 0;
	lent = 0;
	scanf("%s", str);
	for (i = 0; str[i] != '\0';i++) {
		s[lens++] = str[i];
	}
	scanf("%s", str);
	for (i = 0; str[i] != '\0'; i++) {
		t[lent++] = str[i];
	}
	free(str);
}

void appendA() {//������ A�� ����
	lent--;
}

void reverseAppendB() {//������ B�� ���ְ�, ���ڿ��� ������
	int i,e;
	int tmp;
	lent--;
	for (i = 0, e = lent - 1; i < e; i++,e--) {
		tmp = t[i];
		t[i] = t[e];
		t[e] = tmp;
	}
}

int isEqual() {//���ڿ��� �ٸ��� 0, ������ 1��ȯ
	int i;
	for (i = 0; i < lens; i++) {
		if (s[i] != t[i]) {
			return 0;
		}
	}
	return 1;
}

void cal() {//���ڿ� t���� ������ �����Ͽ� s�� �Ǵ��� Ȯ��
	while (lent != lens) {//���� ���̰� ������ ������
		if (t[lent - 1] == 'A') {//�������� A��, A�� ���̴� �Լ��� �������
			appendA();//A����
		}
		else {//�������� B�̸�, ���ڿ��� ������, B�� ���̴� �Լ��� �������
			reverseAppendB();//B�� �����ϰ� ���ڿ��� ������
		}
	}
	if (isEqual() == 0) {//���ڿ��� �ٸ���
		printf("0");
	}
	else {//���ڿ��� ������
		printf("1");
	}
}