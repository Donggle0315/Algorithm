#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i, a,maxi, max=0;
    for (i = 1; i <= 9; i++) {
        scanf("%d", &a);
        if (a > max) {
            max = a;
            maxi = i;
        }
    }
    printf("%d\n%d", max, maxi);


    return 0;
}