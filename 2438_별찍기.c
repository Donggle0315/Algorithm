#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i, j, num;
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}