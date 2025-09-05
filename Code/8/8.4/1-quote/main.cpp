#include <stdio.h>

//当你要在子函数中修改主函数中的变量，就要加引用
void modify_num(int &b)//形参中写&，要称为引用
{
    b=b+1;
}
//c++的引用讲解
//在子函数中修改主函数的普通变量的值
int main() {
    int a=10;
    modify_num(a);
    printf("after modify_num a=%d\n",a);
    return 0;
}
