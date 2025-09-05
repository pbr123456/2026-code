#include <stdio.h>
//练习printf
int main() {
    int age = 21;
    printf("Hello %s, you are %d years old\n", "Bob", age);
    int i=1001;
    float f=96.3;
    printf("student number=%4d, score=%5.2f\n", i, f);
    i=100;
    f=98.21;
    printf("student number=%-4d, score=%5.2f\n", i, f);//默认是右对齐，如果加负号则是左对齐
    return 0;
}
