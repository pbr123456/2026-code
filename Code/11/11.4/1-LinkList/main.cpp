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

int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    return 0;
}
