#include <stdio.h>

void change(int *j)
{
    *j = 5;//通过间接访问得到变量i的空间
}

int main() {
    int i=10;
    printf("before change i=%d\n",i);
    change(&i);//实参是&i
    printf("after change i=%d\n",i);
    return 0;
}
