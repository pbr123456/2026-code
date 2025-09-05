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

//交换两个元素
void swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//挖坑法
//快排核心函数
int partition(ElemType *A,int low,int high)
{
    ElemType pivot = A[low];//拿最左边的作为分割值
    while(low < high)
    {
        while(low < high&&A[high] >= pivot)
            high--;
        A[low] = A[high];//把比分割值小的那个元素，放到A[low]
        while(low < high&&A[low] <= pivot)
            ++low;
        A[high] = A[low];//把分割值大的元素放到A[high]，因为刚才high位置的元素已经放到了low位置
    }
    A[low] = pivot;
    return low;//返回分割值所在的下标
}

//快速排序
void QuickSort(ElemType *A,int low,int high)
{
    if(low<high)
    {
        int pivot_pos = partition(A,low,high);//pivot用来存分割值的位置
        QuickSort(A,low,pivot_pos-1);//排序前一半
        QuickSort(A,pivot_pos+1,high);//排序后一半
    }
}

int main()
{
    SSTable ST;
    ST_Init(ST,10);
    ST_Print(ST);//随机后的数组打印
    QuickSort(ST.elem,0,9);//冒泡排序
    ST_Print(ST);//排序后的数组打印
}