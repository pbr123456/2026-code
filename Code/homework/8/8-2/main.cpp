#include<stdio.h>
#include<stdlib.h>

void myfgets(char *&p)
{
    p=(char *)malloc(100);
    fgets(p,100,stdin);
}

int main() {
    char *p;
    myfgets(p);
    puts(p);
    return 0;
}
