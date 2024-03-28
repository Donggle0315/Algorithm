#include <stdio.h>

int main() {
    char str[20];
    scanf("%10[1234567890]",str);

    printf("%s\n",str);
    return 0;
}