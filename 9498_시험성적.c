#include <stdio.h>

int main() {
	char grade;
	int score;
	scanf("%d",&score);
	grade=score>=90?'A':score>=80?'B':score>=70?'C':score>=60?'D':'F';
	printf("%c",grade);
	
	return 0;
}
