#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &s)
{
    s.top = -1;//代表栈为空
}

//入栈
bool Push(SqStack &s,ElemType x)
{
    if(s.top == MaxSize-1)//代表栈满
        return false;
    s.data[++s.top] = x;
    return true;
}

//出栈
bool Pop(SqStack &s,ElemType &x)
{
    if(s.top == -1)//代表栈空
        return false;
    x = s.data[s.top--];
    return true;
}

typedef struct {
    ElemType data[MaxSize];
    int front,rear;//队头，队尾
}SqQueue;

void InitQueue(SqQueue &q)
{
    q.front = q.rear = 0;
}

//入队
bool EnQueue(SqQueue &q,ElemType x)
{
    if((q.rear+1)%MaxSize == q.front)//判断队列满
        return false;
    q.data[q.rear] = x;
    q.rear = (q.rear+1)%MaxSize;
    return true;
}

//出队
bool DeQueue(SqQueue &q,ElemType &x)
{
    if(q.rear == q.front)//判断队列是否为空
        return false;
    x = q.data[q.front];
    q.front = (q.front+1)%MaxSize;
    return true;
}

int main()
{
    SqStack s;
    ElemType element_1;
    InitStack(s);
    for(int i=0;i<3;i++)
    {
        scanf("%d",&element_1);
        Push(s,element_1);
    }
    for(int i=0;i<3;i++)
    {
        Pop(s,element_1);
        printf("%2d",element_1);
    }
    printf("\n");

    SqQueue q;
    ElemType element_2;
    InitQueue(q);
    bool flag;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&element_2);
        flag = EnQueue(q,element_2);
        if(flag == false)
            printf("false\n");
    }
    for(int i=0;i<4;i++)
    {
        DeQueue(q,element_2);
        printf("%2d",element_2);
    }
    printf("\n");
    return 0;
}