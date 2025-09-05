#include <stdio.h>

//stu等价于struct student,pstu等价于struct student*
typedef struct student{
    int num;
    char name[20];
    char sex;
}stu,*pstu;

typedef int INGETER;

int main() {
    stu s={1001,"wangdao",'M'};
    //stu *p=&s;//定义了一个结构体指针变量
    pstu p1=&s;//定义了一个结构体指针变量
    INGETER num=10;
    printf("i=%d p1->num=%d\n",num,p1->num);
    return 0;
}
