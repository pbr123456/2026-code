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

//前序遍历
void PreOrder(BiTree tree)
{
    if(tree != NULL)
    {
        printf("%c",tree->c);
        PreOrder(tree->lchild);//打印左子树
        PreOrder(tree->rchild);//打印右子树
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
    //前序遍历
    PreOrder(tree);
}