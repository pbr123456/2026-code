#include <stdio.h>
//符号常量
#define PI 3+2
int main() {
    int i = PI*2;//i就是个整形变量
    printf("i=%d\n",i); //3+2*2 = 7
    printf("i size=%d\n", sizeof(i));//sizeof可以用于计算某个变量的空间大小
    return 0;
}
