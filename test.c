#include <stdio.h>

int main() {
    float gr = 0.00006479;
    float once = 0.02835;
    float lb = 0.45359;

    int kg ;
    scanf("%d", &kg);

    printf("%f\n",kg / gr);
    printf("%f\n",kg / once);
    printf("%f\n",kg / lb);
    
    return 0;
}