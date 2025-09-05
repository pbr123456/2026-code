#include <stdio.h>
//全局变量
int i=10;//i是一个全局变量,不建议使用

void print(int a)
{
    printf("I am print i=%d\n",i);
}

int main() {
    printf("main i=%d\n",i);
    i=5;
    print(5);
    return 0;
}
