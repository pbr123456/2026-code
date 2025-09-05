#include <stdio.h>

int main() {
    int a[100];
    int i;
    int total=0;
    scanf("%d",&i);
    for(int j=0;j<i;j++)
        scanf("%d",&a[j]);
    for(int j=0;j<i;j++)
        if (a[j] == 2)
            total++;
    printf("%d",total);
    return 0;
}
