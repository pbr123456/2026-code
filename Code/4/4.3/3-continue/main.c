#include <stdio.h>

int main() {
    int i,total;
    total=0;
    for(i=1;i<=100;i++)
    {
        if(i%2==0)
            continue;
        total += i;
    }
    printf("total=%d\n",total);
    return 0;
}
