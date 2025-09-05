#include <stdio.h>

int main() {
    int i;
    while(scanf("%d",&i))
    {
        if(i>=3 && i<=10)
            printf("i is between 3 and 10.\n");
        else
            printf("i is not between 3 and 10.\n");
    }
    return 0;
}
