#include <stdio.h>

//scanf用来读取标准输入，scanf把标准输入内的内容，需要放到某个变量空间里，因此变量需要取地址
//scanf会阻塞，是因为标准输入缓冲区是空的
int main() {
    int i;
    char c;
    float j;
    scanf("%d",&i);
    printf("i=%d\n",i);
//    fflush(stdin);//清空标准输入缓冲区
//    scanf("%c",&c);
//    printf("c=%c",c);
    scanf("%f",&j);
    printf("j=%f\n",j);
    return 0;
}
