#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d %d",&a,&b)!=EOF) {
        printf("%d\n", a + b);
        if (!(0 < a && a < 10 || 0 < b && b < 10)) {
            break;
        }
    }

    return 0;
}