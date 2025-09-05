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

//删除
void DeleteNode(BiTree &root,KeyType x)
{
    if(root == NULL)
        return;
    if(root->key>x)//当前结点大于要删除的结点，往左子树找
        DeleteNode(root->lchild,x);
    else if(root->key<x)//当前结点小于要删除的结点，往右子树找
        DeleteNode(root->rchild,x);
    else{//找到要删除的结点
        if(root->lchild == NULL)//左孩子为空
        {
            BiTree tempNode = root;
            root = root->rchild;
            free(tempNode);
        }else if(root->rchild == NULL)//右孩子为空
        {
            BiTree tempNode = root;
            root = root->lchild;
            free(tempNode);
        }else{//左右孩子都不为空
            //一般的删除策略是左子树的最大数据 或者 右子树的最小数据
            //代替要删除的结点(这里采用查找左子树的最大数据来代替，左子树的最右节点)
            BiTree tempNode = root->lchild;
            while(tempNode->rchild != NULL)
                tempNode = tempNode->rchild;
            root->key = tempNode->key;//把tempNode对应的值替换到要删除的值的位置上
            DeleteNode(root->lchild,tempNode->key);//在左子树中找到tempNode的值，并删除
        }
    }
}

//树中不放入相同元素
//二叉排序树新建，中序遍历，查找，删除
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
    DeleteNode(T,40);//删除某个结点
    InOrder(T);
    return  0;
}
