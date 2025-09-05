#include <stdio.h>
//指针-间接访问
int main() {
    int i=5;
    char c='a';
    int *i_pointer = &i;//定制整形变量指针i_pointer，并初始化
    char *c_pointer;
    c_pointer = &c;
    *i_pointer = 10;//间接访问
    printf("%d\n",i);
    return 0;
}
