#include <stdio.h>

int main() {
    int i,total;
    total=0;
    for(i=1;i<=100;i++)
    {
        if(total>2000)
            break;//当和大于2000，退出循环
        total += i;
    }
    printf("total=%d\n",total);
    return 0;
}
