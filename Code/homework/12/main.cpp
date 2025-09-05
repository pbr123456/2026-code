#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode *next;//指针域
}LNode,*LinkList;

LinkList list_tail_insert(LinkList &L)
{
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    scanf("%d",&x);
    LinkList s,r=L;
    while(x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

LinkList GetElem(LinkList L,int i)
{
    int j=1;
    if(i==0)
        return L;
    if(i<1)
        return NULL;
    LinkList p = L->next;
    while(p && j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool ListFrontInsert(LinkList L,int i,ElemType e)
{
    LinkList p = GetElem(L,i-1);//找到前一个结点的位置
    if(p == NULL)
        return false;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList L,int i)
{
    LinkList p = GetElem(L,i-1);
    if(p==NULL)
        return false;
    LinkList q;//用来存储被删除的结点
    q = p->next;
    if(q==NULL)
        return false;
    p->next = q->next;
    free(q);
    return true;
}

void print_list(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}

int main()
{
    LinkList L;
    list_tail_insert(L);
    LinkList p = GetElem(L,2);
    printf("%d\n",p->data);
    ListFrontInsert(L,2,99);
    print_list(L);
    ListDelete(L,4);
    print_list(L);
}