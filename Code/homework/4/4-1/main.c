#include <stdio.h>
//判断是否为对称数
int main() {
    int i,j,temp;
    j=0;
    scanf("%d",&i);
    temp = i;
    while(temp!=0)
    {
        j *= 10;
        j += temp%10;
        temp /= 10;
    }
    if(j==i)
        printf("yes");
    else
        printf("no");
    return 0;
}
