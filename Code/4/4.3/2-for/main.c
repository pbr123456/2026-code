#include <stdio.h>
//for循环实现从1加到100
int main() {
    int i;
    int total=0;
    for(i=1;i<=100;i++)
        total += i;
    printf("total=%d\n",total);
    return 0;
}
