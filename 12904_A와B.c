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

void appendA() {//마지막 A를 없앰
	lent--;
}

void reverseAppendB() {//마지막 B를 없애고, 문자열을 뒤집음
	int i,e;
	int tmp;
	lent--;
	for (i = 0, e = lent - 1; i < e; i++,e--) {
		tmp = t[i];
		t[i] = t[e];
		t[e] = tmp;
	}
}

int isEqual() {//문자열이 다르면 0, 같으면 1반환
	int i;
	for (i = 0; i < lens; i++) {
		if (s[i] != t[i]) {
			return 0;
		}
	}
	return 1;
}

void cal() {//문자열 t에서 역으로 연산하여 s가 되는지 확인
	while (lent != lens) {//둘의 길이가 같이질 때까지
		if (t[lent - 1] == 'A') {//마지막이 A면, A를 붙이는 함수를 사용했음
			appendA();//A삭제
		}
		else {//마지막이 B이면, 문자열을 뒤집고, B를 붙이는 함수를 사용했음
			reverseAppendB();//B를 삭제하고 문자열을 뒤집음
		}
	}
	if (isEqual() == 0) {//문자열이 다르면
		printf("0");
	}
	else {//문자열이 같으면
		printf("1");
	}
}