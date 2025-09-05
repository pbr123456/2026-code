#include <stdio.h>

struct student_type1{
    double score;//8个字节
    int height;
    short age;//2个字节
};//占用16字节大小的空间

struct student_type2{
    int height;
    char sex;
    short age;
};//占用8个字节大小的空间

int main() {
    struct student_type1 s1={4,5,6};
    struct student_type2 s2={7,'m',8};
    printf("s1 size=%u\n", sizeof(s1));
    printf("s2 size=%u\n", sizeof(s2));
    return 0;
}
