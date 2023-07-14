#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i, num;
    scanf("%d", &num);
    for (i = num; i > 0; i--) {
        printf("%d\n", i);
    }


    return 0;
}