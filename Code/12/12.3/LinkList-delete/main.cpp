#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode *next;//指针域
}LNode,*LinkList;

void list_tail_insert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList p,r=L;
    while(x != 9999)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->data = x;
        r->next = p;
        r = p;
        scanf("%d",&x);
    }
    r->next = NULL;
}

LinkList GetElem(LinkList L,int i)
{
    int j=1;
    LinkList p = L->next;
    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while(p&&j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool ListDelete(LinkList L,int i)
{
    LinkList p = GetElem(L,i-1);//获取前一个结点的指针
    if(p == NULL)
        return false;
    LinkList q;//用于存储被删掉的结点
    q = p->next;
    if(q == NULL)
        return false;
    p->next = q->next;
    free(q);
    return true;
}

void print_list(LinkList L)
{
    L = L->next;
    while(L != NULL)
    {
        printf("%3d",L->data);
        L = L->next;
    }
    printf("\n");
}

int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);//打印链表
    ListDelete(L,2);
    print_list(L);//打印链表
    return 0;
}