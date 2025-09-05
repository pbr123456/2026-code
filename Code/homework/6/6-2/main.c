#include <stdio.h>
#include<stdlib.h>

int main() {
    char *p;
    int n;
    char a;
    scanf("%d",&n);
    p= (char *)malloc(n);
    scanf("%c",&a);//吞掉第一次输入遗留的换行符
    fgets(p,n,stdin);
    puts(p);
    return 0;
}
