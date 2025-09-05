#include <stdio.h>
//计算1到100的和
int main() {
    int i=1,total=0;
    while(i<=100)
    {
        total += i;
        i++;
    }
    printf("total=%d\n",total);
    return 0;
}
