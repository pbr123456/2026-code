#include <stdio.h>
//强制类型转换
int main() {
    int i=5;
    float j=i/2;//这里做的是整形运算，因为左右操作数都是整形
    float k=(float)i/2;
    printf("%f\n",j);
    printf("%f\n",k);
    return 0;
}
