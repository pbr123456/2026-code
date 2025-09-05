#include <stdio.h>
//scanf-一次读取多种数据类型
int main() {
    int i,ret;
    float f;
    char c;
    ret = scanf("%d %c%f",&i,&c,&f);//要在%c前加空格，因为不加空格会读取到空格导致后面的浮点型读取不了
    printf("i=%d,c=%c,f=%5.2f\n",i,c,f);
    return 0;
}
