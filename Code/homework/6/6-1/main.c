#include <stdio.h>

void change(int *temp)
{
    *temp = (*temp)/2;
}

int main() {
    int a;
    scanf("%d",&a);
    change(&a);
    printf("%d\n",a);
    return 0;
}
