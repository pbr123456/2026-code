#include <stdio.h>

void change(int j)//j是形参
{
    j=5;
}

int main() {
    int i=10;
    printf("before change i=%d\n",i);
    change(i);//调用change函数时，实参赋值给形参
    printf("after change i=%d\n",i);
    return 0;
}
