#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode *next;//指针域
}LNode, *LinkList;

//利用尾插法新建链表
void list_tail_insert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    ElemType x;
    scanf("%d",&x);
    L->next=NULL;
    LNode *s,*r=L;//s用于指向申请的新结点,r始终指向链表尾部
    while(x!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));//为s申请空间
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
}

void print_list(LinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%3d",L->data);
        L = L->next;
    }
    printf("\n");
}

//按位查找
LinkList GetElem(LinkList L,int SearchPos)
{
    int i=0;
    if(SearchPos<0)
        return NULL;
    while(L && i<SearchPos)
    {
        L=L->next;
        i++;
    }
    return L;
}

//将新结点插入到第i个结点的后边
bool ListFrontInsert(LinkList L,int i,ElemType InsertVal)
{
    LinkList p = GetElem(L,i-1);
    if(p==NULL)
        return false;
    LinkList q;
    q = (LinkList)malloc(sizeof(LNode));//为新结点申请阔能空间
    q->data = InsertVal;
    q->next = p->next;
    p->next = q;
    return true;
}

int main() {
    LinkList L;
    LinkList search;
    list_tail_insert(L);
    print_list(L);
    ListFrontInsert(L,2,99);//新节点插入到第i个位置
    print_list(L);
    return 0;
}
