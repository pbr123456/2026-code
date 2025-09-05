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

//找到链表中间结点，并设置好L2链表
void find_middle(LinkList L,LinkList &L2)
{
    L2 = (LinkList)malloc(sizeof(LNode));//第二条链表的头结点
    LinkList pcur,ppre;//双指针法遍历，考研初试常考
    ppre = pcur = L->next;
    while(pcur)
    {
        pcur = pcur->next;
        if(pcur==NULL)//为了防止pcur为NULL
            break;
        pcur = pcur->next;
        if(pcur==NULL)//为了使得偶数个，ppre依然指向o1，o2,到o6中的o3结点
            break;
        ppre = ppre->next;
    }
    L2->next = ppre->next;//由L2头结点指向后面一半
    ppre->next = NULL;//前一半链表的最后一个结点，next要为NULL
}

void reverse(LinkList L2)
{
    LinkList r,s,t;
    r = L2->next;
    if(r==NULL)
        return;//链表为空，直接返回
    s=r->next;
    if(s==NULL)
        return;//链表只有一个结点
    t=s->next;
    while(t)
    {
        s->next = r;
        r = s;//以下三个指针同时往后走一步
        s = t;
        t = t->next;
    }
    s->next = r;
    L2->next->next = NULL;//逆置后的链表尾部要为空
    L2->next = s;
}

void merge(LinkList L,LinkList L2)
{
    LinkList pcur,p,q;
    pcur = L->next;//pcur始终指向组合后链表的链表尾
    p = pcur->next;//p是用来遍历L链表
    q = L2->next;//q指向L2第一个结点，用来遍历L2链表
    while(p!=NULL&&q!=NULL)
    {
        pcur->next = q;
        q = q->next;
        pcur = pcur->next;
        pcur->next = p;
        p = p->next;
        pcur = pcur->next;
    }
    //任何一个链表都可能剩余一个结点，放进来即可
    if(p!=NULL)
    {
        pcur->next = p;
    }
    if(q!=NULL)
    {
        pcur->next = q;
    }
}

int main() {
    LinkList L;//链表头
    list_tail_insert(L);//利用尾插法
    print_list(L);//打印链表
    //寻找中间结点，并返回第二条链表
    LinkList L2=NULL;
    find_middle(L,L2);//只有一个节结点时，L2是没有结点的
    printf("-------------------------------\n");
    print_list(L);
    print_list(L2);//打印链表
    printf("-------------------------------\n");
    reverse(L2);//逆转L2链表
    print_list(L2);//打印链表
    printf("-------------------------------\n");
    merge(L,L2);//交替合并两个链表的结点
    free(L2);
    print_list(L);
    return 0;
}