#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

typedef struct tag{
    BiTree p;//树的某一个节点
    struct tag *pnext;
}tag_t,*ptag_t;

//中序遍历
void InOrder(BiTree tree)
{
    if(tree != NULL)
    {
        InOrder(tree->lchild);//打印左子树
        printf("%c",tree->c);
        InOrder(tree->rchild);//打印右子树
    }
}

//后序遍历
void PostOrder(BiTree tree)
{
    if(tree != NULL)
    {
        PostOrder(tree->lchild);//打印左子树
        PostOrder(tree->rchild);//打印右子树
        printf("%c",tree->c);
    }
}

//队列的结构体
typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;//链表头，链表尾
}LinkQueue;//先进先出

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

void LeverOrder(BiTree T)
{
    LinkQueue Q;//辅助队列
    InitQueue(Q);//初始化队列
    BiTree q;//存储出队的结点
    EnQueue(Q,T);
    while(!IsEmpty(Q))
    {
        DeQueue(Q,q);
        putchar(q->c);
        if(q->lchild != NULL)
            EnQueue(Q,q->lchild);
        if(q->rchild != NULL)
            EnQueue(Q,q->rchild);
    }
}

int main()
{
    BiTree pnew;//申请树的一个新结点
    BiTree tree = NULL;
    ptag_t phead = NULL,ptail = NULL,listpnew = NULL,pcur = NULL;
    char c;
    while(scanf("%c",&c))
    {
        if(c == '\n')
            break;
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->c = c;
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;
        //如果是树的第一个结点
        if(tree == NULL)
        {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
            continue;
        }
        else{
            //让元素先进入队列
            ptail->pnext = listpnew;
            ptail = listpnew;
        }
        //把结点放入树中
        if(pcur->p->lchild == NULL)
            pcur->p->lchild = pnew;
        else if(pcur->p->rchild == NULL)
        {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }
    //中序遍历
    InOrder(tree);
    printf("\n");
    //后序遍历
    PostOrder(tree);
    printf("\n");
    //层次遍历
    LeverOrder(tree);
}