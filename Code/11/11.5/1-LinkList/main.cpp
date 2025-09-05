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

//按值查找
LinkList LocateElem(LinkList L,ElemType SearchValue)
{
    while(L)
    {
        if(L->data==SearchValue)//如果找到对应的值，就返回那个结点的地址
            return L;
        L=L->next;
    }
    return NULL;
}

int main() {
    LinkList L;
    LinkList search;
    list_tail_insert(L);
    print_list(L);
    search = GetElem(L,2);//按位查找
    if(search != NULL)
    {
        printf("Succeeded in searching by serial number\n");
        printf("%d\n",search->data);
    }
    search = LocateElem(L,5);//按值查找
    if(search != NULL)
    {
        printf("Search by value succeeded\n");
        printf("%d\n",search->data);
    }
    return 0;
}
