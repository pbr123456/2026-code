#include <stdio.h>
#include<string.h>

int main() {
    char c[20];
    char d[20];
    gets(c);
    int len = strlen(c);
    strcpy(d,c);
    for(int i=0; i<len; i++)
        d[i] = d[len-i-1];
    int result = strcmp(c,d);
    if(result > 0)
        printf("1");
    else if(result == 0)
        printf("0");
    else
        printf("-1");
    return 0;
}
