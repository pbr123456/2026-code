#include <stdio.h>

//利用递归实现n的阶乘  f(n)=n*f(n-1)
int f(int n)
{
    //一定要有结束条件
    if(n==1)
        return 1;
    return n*f(n-1);
}

//上台阶，到第n个台阶，有多少种走法(要么一次走一格，要么一次走两格)
int step(int n)
{
    if(n==1 || n==2)//当台阶只有1个或者2个，就递归结束
        return n;
    return step(n-1)+ step(n-2);
}

int main() {
    int i;
    scanf("%d",&i);
    //printf("f(%d)=%d\n",i,f(i));
    printf("step(%d)=%d\n",i, step(i));
    return 0;
}
