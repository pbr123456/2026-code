#include "function.h"

//层次建树
int main() {
    BiTree pnew;//申请树的一个新结点
    BiTree tree = NULL;//tree是指向树根，代表树
    //phead就是队列头，ptail就是队列尾
    ptag_t phead = NULL,ptail = NULL,listpnew = NULL,pcur = NULL;
    char c;
    //abcdefghij
    while(scanf("%c",&c))
    {
        if(c == '\n')
            break;//读到换行就结束
        //calloc申请的空间大小是两个参数直接相乘，并对空间进行初始化，赋值为0
        pnew = (BiTree)calloc(1,sizeof(BiTNode));
        pnew->c = c;
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));//给队列结点申请空间
        listpnew->p = pnew;
        //如果是树的第一个结点
        if(tree == NULL)
        {
            tree = pnew;//tree指向树的根节点
            phead = listpnew;//第一个结点既是队列头，也是队列尾
            ptail = listpnew;
            pcur = listpnew;//pcur要指向要进入树的父亲元素
            continue;
        }
        else{
            //让元素先入队列
            ptail->pnext = listpnew;//新结点放入链表，通过尾插法
            ptail = listpnew;//指向队列尾部
        }
        //接下来把结点放入树中
        if(pcur->p->lchild == NULL)//左孩子为空
            pcur->p->lchild = pnew;
        else if(pcur->p->rchild == NULL)//右孩子为空
        {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;//当前结点左右孩子都有了，pcur就指向下一个结点
        }
    }
    return 0;
}
