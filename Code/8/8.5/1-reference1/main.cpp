#include <stdio.h>

typedef struct student{
    int num;
    float score;
}stu;

//在这里增加引用&,在子函数中操作s和在主函数中操作是等价的
void change(stu &s)
{
    s.num=1002;
    s.score=85.0;
}

int main() {
    stu s={1001,90.5};
    printf("num:%d,score=%.1f\n",s.num,s.score);
    change(s);
    printf("after_change num:%d,score=%.1f\n",s.num,s.score);
    return 0;
}
