#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int num;
    char name[20];
    char sex;
};
//结构体指针的练习
int main() {
    struct student s={1001,"wangle",'M'};
    struct student sarr[3]={1001,"lilei",'M',1005,"zhangsan",'M',1007,"lili",'F'};
    struct student *p;//定义了一个结构体指针
    p=&s;
    //printf("%d %s %c\n",(*p).num,(*p).name,(*p).sex);
    printf("%d %s %c\n",p->num,p->name,p->sex);
    p=sarr;//等价于p=&sarr[0]
    printf("%d %s %c\n",p->num,p->name,p->sex);
    printf("------------------------------------\n");
    p=p+1;
    printf("%d %s %c\n",p->num,p->name,p->sex);
    printf("------------------------------------\n");
    p=p+1;
    printf("%d %s %c\n",p->num,p->name,p->sex);
    //下面给结构体指针p通过malloc申请空间，并对其成员赋值，在访问
    p=(struct student*)malloc(sizeof(struct student));//28个字节
    p->num=100;
    p->sex='M';
    strcpy(p->name,"longge");
    printf("------------------------------------\n");
    printf("%d %s %c\n",p->num,p->name,p->sex);
    return 0;
}
