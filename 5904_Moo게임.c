#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void moo(long long, int, long long);

long long n,count;
char ch;

int main() {
	scanf("%lld", &n);
	moo(n, 1, 3);
	printf("%c", ch);
}


void moo(long long num, int k, long long len) {
	long long new_len;
	if (num <= 3) {
		if (num == 1) {
			ch = 'm';
		}
		else {
			ch = 'o';
		}
		return;
	}
	new_len = len * 2 + k + 3;
	if (new_len < num) {
		moo(num, k + 1, new_len);
	}
	else {
		if (len < num && num < len + k + 4) {
			if (num - len == 1) {
				ch = 'm';
			}
			else {
				ch = 'o';
			}
			return;
		}
		else {
			moo(num - (len + k + 3), 1, 3);
		}
	}
}