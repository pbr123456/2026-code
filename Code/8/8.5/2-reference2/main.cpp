#include <stdio.h>
#include<stdlib.h>

typedef struct student{
    int num;
    float score;
}stu;

//子函数中并没有改变p的地址，只是修改了p指向的结构体中的数据
void change(stu *p)
{
    p->num=2002;
    p->score=85.5;
}

int main() {
    stu *p=(stu*)malloc(sizeof(stu));
    p->num=2001;
    p->score=90.5;
    printf("num:%d,score:%.1f\n",p->num,p->score);
    change(p);
    printf("after_change num:%d,score:%.1f\n",p->num,p->score);
    return 0;
}
