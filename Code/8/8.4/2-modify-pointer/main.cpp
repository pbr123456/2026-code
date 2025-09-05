#include <stdio.h>

void modify_pointer(int *&p,int *q)//引用必须和变量名紧邻
{
    p=q;
}
//子函数内修改主函数的一级指针变量
int main() {
    int *p=NULL;
    int i=10;
    int *q=&i;
    modify_pointer(p,q);
    printf("after modify_pointer *p=%d\n",*p);//当代码最终执行退出
    return 0;//当代码最终执行退出，退出代码不为0，则代表进程异常结束
}
