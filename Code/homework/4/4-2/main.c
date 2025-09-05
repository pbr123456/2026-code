#include <stdio.h>
//求n的阶乘
int main() {
    int n;
    int total = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        total *= i;
    printf("%d\n",total);
    return 0;
}
