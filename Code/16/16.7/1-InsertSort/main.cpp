#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct {
    ElemType *elem;//存储元素的起始地址
    int TableLen;//元素个数
}SSTable;

void ST_Init(SSTable &ST,int len)
{
    ST.TableLen = len;
    //申请一块堆空间，当数组用
    ST.elem = (ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));//随机数生成，每一次执行代码就会得到随机的十个元素
    for(int i=0;i<ST.TableLen;i++)
        ST.elem[i] = rand()%100;//生成的数在0-99之间
}

//打印数组中的元素
void ST_Print(SSTable ST)
{
    for(int i=0;i<ST.TableLen;i++)
        printf("%3d",ST.elem[i]);
    printf("\n");
}

//插入排序
void InsertSort(ElemType *A,int n)
{
    int i,j,insertVal;
    for(i=1;i<n;i++)//外层控制要插入的数
    {
        insertVal = A[i];//保存要插入的数
        //内层控制比较，j要大于等于0，同时A[j]大于insertVal时，A[j]位置元素往后覆盖
        for(j=i-1;j>=0&&A[j]>insertVal;j--)
            A[j+1] = A[j];
        A[j+1] = insertVal;
    }
}

int main()
{
    SSTable ST;
    ST_Init(ST,10);
    ST_Print(ST);//随机后的数组打印
    InsertSort(ST.elem,10);//冒泡排序
    ST_Print(ST);//排序后的数组打印
}