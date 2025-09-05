#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];//数组
    int front,rear;//队列头，队列尾
}SqQueue;
//循环队列的代码实战

//初始化循环队列
void InitQueue(SqQueue &q)
{
    q.front = q.rear = 0;//初始化循环队列，就是让头和尾都是向0
}

//判断循环队列是否为空
bool IsEmpty(SqQueue q)
{
    return q.rear == q.front;
}

//入队
bool EnQueue(SqQueue &q,ElemType x)
{
    //判断循环队列是否满了，满了就不能入队
    if((q.rear+1)%MaxSize == q.front)
        return false;
    q.data[q.rear] = x;//放入元素
    q.rear = (q.rear+1)%MaxSize;//rear要加1，如果大于数组最大下标，回到开头
    return true;
}

//出队
bool DeQueue(SqQueue &q,ElemType &x)
{
    //判断循环队列是否为空
    if(q.rear == q.front)
        return false;
    x = q.data[q.front];
    q.front = (q.front+1)%MaxSize;
    return true;
}

int main() {
    SqQueue q;
    InitQueue(q);
    bool ret;
    ret = IsEmpty(q);
    if(ret)
    {
        printf("SqQueue is Empty\n");
    }
    else
    {
        printf("SqQueue is not Empty\n");
    }
    EnQueue(q,3);
    EnQueue(q,4);
    EnQueue(q,5);
    ret = EnQueue(q,6);
    ret = EnQueue(q,7);
    if(ret)
        printf("EnQueue success\n");
    else
        printf("EnQueue fail\n");
    ElemType element;//存储出队元素
    ret = DeQueue(q,element);
    if(ret)
        printf("DeQueue success\n");
    else
        printf("DeQueue fail\n");
    ret = EnQueue(q,8);
    if(ret)
        printf("EnQueue success\n");
    else
        printf("EnQueue fail\n");
    return 0;
}
