#include <stdio.h>
//指针与一维数组的传递

void change(char *d)
{
    *d = 'H';
    d[1] = 'E';//*(d+1)='E'与其等价
    *(d+2) = 'L';
}

int main() {
    char c[10]="hello";
    change(c);
    puts(c);
    return 0;
}
