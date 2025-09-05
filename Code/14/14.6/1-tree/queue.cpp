#include "function.h"

//初始化队列
void InitQueue(LinkQueue &q)
{
    q.front = q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    q.front->next = NULL;//头结点的next指针为NULL
}

//队列是否为空
bool IsEmpty(LinkQueue q)
{
    if(q.front == q.rear)
        return true;
    else
        return false;
}

//入队
void EnQueue(LinkQueue &q,ElemType x)
{
    LinkNode *pnew = (LinkNode*)malloc(sizeof(LinkNode));
    pnew->data = x;
    pnew->next = NULL;//要让next为NULL
    q.rear->next = pnew;//尾指针的next指向pnew，因为从尾部入队
    q.rear = pnew;//rear要指向新的尾部
}

//出队
bool DeQueue(LinkQueue &q,ElemType &x)//要拿这个元素，所以x要加引用
{
    if(q.rear == q.front)//队列为空
    {
        return false;
    }
    LinkNode *temp = q.front->next;//拿到第一个结点，存入temp
    x = temp->data;
    q.front->next = temp->next;//让第一个结点断链
    if(q.rear == temp)//链表只剩最后一个节点,被删除后要改变rear
    {
        q.rear = q.front;
    }
    free(temp);
    return true;
}
