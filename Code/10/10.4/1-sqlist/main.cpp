#include <stdio.h>
//顺序表的删除和查询操作
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];//让顺序表存储其他类型元素时，可以迅速改变代码
    int len;
}SqList;
//顺序表的插入，因为L会改变，因此我们这里要用引用,i是插入的位置
bool ListInsert(SqList &L,int i,ElemType element)
{
    //判断i是否合法
    if(i<1 && i>L.len+1)
    {
        return false;//未插入返回false
    }
    //如果存储空间满了，就不能插入
    if(L.len==MaxSize)
        return false;//未插入返回false
    //把后面的元素依次往后移，空出位置，来放要插入的元素
    for(int j=L.len;j>=i;j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = element;
    L.len++;//顺序表长度加1
    return true;//插入成功就返回true
}

//打印顺序表
void print(SqList L)
{
    int i;
    for(int i=0;i<L.len;i++)
        printf("%d ",L.data[i]);//为了打印到同一行
    printf("\n");
}

//删除顺序表中的元素,i是要删除的元素的位置，del是为了获取被删除的元素的值
bool ListDelete(SqList &L,int i,ElemType &del)
{
    //判断删除的元素的位置是否合法
    if(i<1 || i>L.len)
        return false;
    del=L.data[i-1];//首先将要删除的元素保存到del中
    for(int j=i;j<L.len;j++)//往前移动元素
        L.data[j-1] = L.data[j];
    L.len--;//顺序表长度减一
    return true;
}

//查找某个元素的位置，找到了就会返回对应位置，没找到则返回0
int LocateElem(SqList L,int e)
{
    int i;
    for(i=0;i<L.len;i++)
        if(e == L.data[i])
            return i+1;//i是数组的下标，而i+1才是顺序表的下标
    return 0;//循环结束没找到，返回0

}

int main() {
    SqList L;//定义一个顺序表
    bool ret;//用来装函数的返回值
    ElemType del;//要删除的元素
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.len=3;
    ret=ListDelete(L,1,del);
    if(ret)
    {
        printf("delete sqlist success\n");
        printf("del element=%d\n",del);
        print(L);//打印链表L
    }
    else
        printf("delete sqlist fail\n");
    int pos;//存储元素位置
    pos=LocateElem(L,2);
    if(pos)
    {
        printf("find this element\n");
        printf("element pos=%d\n",pos);
    }
    else
        printf("don't find this element\n");
    return 0;
}