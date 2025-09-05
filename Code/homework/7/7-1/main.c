#include <stdio.h>

//走台阶
int step(int n)
{
    if(n==1 || n==2)
        return n;
    return step(n-1)+step(n-2);
}

int main() {
    int i;
    scanf("%d",&i);
    printf("%d\n", step(i));
    return 0;
}
