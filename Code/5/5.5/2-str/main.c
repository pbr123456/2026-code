#include <stdio.h>
#include<string.h>

int mystrlen(char c[])
{
    int i=0;
    while(c[i])//找到结束符后结束
    {
        i++;
    }
    return i;
}

int main() {
    int len;
    char c[20];
    char d[100]="world";
    char e[100];
    gets(c);
    puts(c);
    len = strlen(c);//统计字符串的长度
    printf("len=%d\n",len);
    len = mystrlen(c);//统计字符串的长度
    printf("my len=%d\n",len);
    strcat(c,d);//把d中的字符串拼接到c里
    puts(c);
    strcpy(e,c);//把c里面的字符串复制到e里面
    puts(e);
    printf("c?d %d\n", strcmp(c,d));//c大于d，返回值正值，相同则为0，小于则为负值
    return 0;
}
