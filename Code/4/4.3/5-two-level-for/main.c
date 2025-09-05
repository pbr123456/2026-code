#include <stdio.h>

int main() {
    int i,j;
    for(i=0;i<5;i++)
    {
        printf("i=%d\n",i);//打印i，就知道是第几次进行外层循环
        for(j=0;j<5;j++)
        {
            printf("%d ",i*j);
        }
        printf("\n");
    }
    return 0;
}
