#include <stdio.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];//让顺序表存储其他类型元素时，可以迅速改变代码
    int len;
}SqList;

bool sqlistinsert(SqList &L,int pos,ElemType elem)
{
    if(pos<1 || pos>L.len+1)
        return false;
    if(L.len>=MaxSize)
        return false;
    for(int i=L.len;i>=pos;i--)
        L.data[i] = L.data[i-1];
    L.data[pos-1] = elem;
    L.len++;
    return true;
}

bool sqlistdelete(SqList &L,int pos)
{
    if(pos<1 || pos>L.len+1)
        return false;
    for(int i=pos;i<L.len;i++)
        L.data[i-1] = L.data[i];
    L.len--;
    return true;
}

void print(SqList L)
{
    for(int i=0;i<L.len;i++)
        printf("%3d",L.data[i]);
    printf("\n");
}

int main() {
    SqList L;
    int a,b;
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.len=3;
    scanf("%d",&a);//第一次输入插入的元素值
    scanf("%d",&b);//第二次删除元素的位置
    bool ret;
    ret=sqlistinsert(L,2,a);
    if(ret)
        print(L);
    bool ret_1;
    ret_1=sqlistdelete(L,b);
    if(ret_1)
        print(L);
    else
        printf("false\n");
    return 0;
}
