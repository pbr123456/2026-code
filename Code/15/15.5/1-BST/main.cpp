#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;

//插入54,20,66,40,28,79,58
//非递归的创建二叉树
int BST_Insert(BiTree &T,KeyType k)
{
    if(T == NULL)//如果树为空，新结点作为树的根
    {
        T = (BiTree)calloc(1, sizeof(BSTNode));
        T->key = k;
        T->rchild = T->lchild = NULL;
        return 1;//代表插入成功
    }
    BiTree p=T,parent;//用来遍历树
    while(p)
    {
        parent = p;//parent用来存p的父亲
        if(k>p->key)
            p = p->rchild;
        else if(k<p->key)
            p = p->lchild;
        else
            return 0;//相等的元素不可以放入查找树
    }
    //接下来要判断放到父亲的左边还是右边
    BiTree pnew = (BiTree)calloc(1,sizeof(BSTNode));
    pnew->key = k;
    pnew->lchild = pnew->rchild = NULL;
    if(k>parent->key)
        parent->rchild = pnew;
    else
        parent->lchild = pnew;
    return 0;
}

//新建二叉树
void Create_BST(BiTree &T, KeyType *str, int len)
{
    int i;
    for(i=0;i<len;i++)
        BST_Insert(T,str[i]);
}

void InOrder(BiTree tree)
{
    if(tree != NULL)
    {
        InOrder(tree->lchild);
        printf("%3d",tree->key);
        InOrder(tree->rchild);
    }
}

BiTree BST_Search(BiTree T,KeyType k,BiTree &parent)
{
    parent = NULL;//存储要找的结点的父亲
    while(T != NULL && k != T->key)
    {
        parent = T;
        if(k>T->key)
            T = T->rchild;
        else
            T = T->lchild;
    }
    return T;
}

//树中不放入相同元素
//二叉排序树新建，中序遍历，查找
int main()
{
    BiTree T = NULL;//树根
    BiTree parent;//存储父亲结点的地址值
    BiTree search;
    KeyType str[7] = {54,20,66,40,28,79,58};
    Create_BST(T,str,7);//创建二叉排序树
    InOrder(T);//中序遍历二叉树是由小到大的
    printf("\n");
    search = BST_Search(T,40,parent);
    if(search)
        printf("find key = %d\n",search->key);
    else
        printf("not find\n");
    return  0;
}
