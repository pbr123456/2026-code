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

void InOrder(BiTree tree,KeyType str[],int &pos)
{
    if(tree != NULL)
    {
        InOrder(tree->lchild,str,pos);
        printf("%3d",tree->key);
        str[pos++] = tree->key;
        InOrder(tree->rchild,str,pos);
    }
}

typedef int ElemType;
typedef struct {
    ElemType *elem;//整形指针，申请堆空间的起始地址存入elem
    int TableLen;//存储动态数组里边元素的个数
}SSTable;

//二分查找
int BinarySearch(SSTable L,ElemType key)
{
    int low=0;
    int high = L.TableLen-1;
    int mid;
    while(low<=high)//low<=high,可以取到low，也能取到high
    {
        mid = (low+high)/2;
        if(key > L.elem[mid])
            low = mid+1;
        else if(key < L.elem[mid])
            high = mid-1;
        else
            return mid;
    }
    return -1;//没找到
}

//树中不放入相同元素
//二叉排序树新建，中序遍历，查找
int main()
{
    BiTree T = NULL;//树根
    BiTree parent;//存储父亲结点的地址值
    int search;
    KeyType str[10];
    for(int i=0;i<10;i++)
        scanf("%d",&str[i]);
    Create_BST(T,str,10);//创建二叉排序树
    int pos=0;
    InOrder(T,str,pos);//中序遍历二叉树是由小到大的
    printf("\n");
    SSTable st;
    st.elem = str;
    st.TableLen = 10;
    search = BinarySearch(st,21);
    printf("%d\n",search);
    return  0;
}
