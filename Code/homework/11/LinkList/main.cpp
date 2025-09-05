#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode *next;//指针域
}LNode, *LinkList;

//利用头插法创建链表
void list_head_insert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList s;
    while(x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
}

//利用尾插法创建链表
void list_tail_insert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList s,p=L;//p永远指向链表的最后一位
    while(x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        p->next = s;
        p = s;
        scanf("%d",&x);
    }
    p->next = NULL;
}

//打印链表
void print_list(LinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%d",L->data);//打印当前结点数据
        L=L->next;//指向下一个结点
        if(L!=NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    LinkList L,P;
    list_head_insert(L);//输入数据可以为3 4 5 6 7 999，头插法新建链表
    print_list(L);//打印链表
    list_tail_insert(P);
    print_list(P);//打印链表
    return 0;
}