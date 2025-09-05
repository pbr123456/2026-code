#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];//数组
    int top;//始终指向栈顶的一个变量
}SqStack;

//初始化栈
void InitStack(SqStack &s)
{
    s.top = -1;//栈为空
}

//判断栈是否为空
bool StackEmpty(SqStack s)
{
    if(s.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &s,ElemType x)
{
    //判断栈是否满了
    if(s.top == MaxSize-1)
        return false;
    s.data[++s.top] = x;
    //等价于
    //s.top++;
    //s.data[s.top] = x;
    return true;
}

//获取栈顶元素
bool GetTop(SqStack s,ElemType &m)
{
    //判断栈是否为空
    if(StackEmpty(s))
        return false;
    m = s.data[s.top];
    return true;
}

//弹出栈顶元素
bool Pop(SqStack &s,ElemType &m)
{
    //判断栈是否为空
    if(StackEmpty(s))
        return false;
    m = s.data[s.top--];//出栈
    //等价于
    //m = s.data[s.top];
    //s.top--;
    return true;
}

int main()
{
    SqStack s;
    InitStack(s);
    bool flag;
    flag = StackEmpty(s);
    if(flag)
    {
        printf("stack is empty\n");
    }
    Push(s,3);//入栈元素为3
    Push(s,4);//入栈元素为4
    Push(s,5);//入栈元素为5
    ElemType m;
    flag = GetTop(s,m);//获取栈顶元素
    if(flag)
    {
        printf("get top %d\n",m);
    }
    flag = Pop(s,m);//弹出栈顶元素
    if(flag)
    {
        printf("pop element %d\n",m);
    }
    return 0;
}

