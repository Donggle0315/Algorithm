#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int i,num, serialNo = 0;
    for (i = 0; i < 5; i++) {
        scanf("%d", &num);
        serialNo += pow(num, 2);
    }
    serialNo %= 10;
    printf("%d", serialNo);

    return 0;
}