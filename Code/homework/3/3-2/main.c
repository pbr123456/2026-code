#include <stdio.h>

int main() {
    int i;
    char j;
    float k;
    scanf("%d %c%f",&i,&j,&k);
    float result = i + j + k;
    printf("%0.2f\n",result);
    return 0;
}
