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

//交换元素
void swap(ElemType &a,ElemType &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//冒泡排序
void BubbleSort(ElemType *arr,int len)
{
    bool flag;
    for(int i=0;i<len;i++)
    {
        flag = false;
        for(int j=len-1;j>i;j--)
            if(arr[j-1]>arr[j])
            {
                swap(arr[j-1],arr[j]);
                flag = true;
            }
        if(flag == false)
            return;
    }
}

//快排核心部分
int Partition(ElemType *arr,int low,int high)
{
    ElemType pivot = arr[low];
    while(low<high)
    {
        while(low<high&&pivot<=arr[high])
            high--;
        arr[low] = arr[high];
        while(low<high&&pivot>=arr[low])
            low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

//快速排序
void QuickSort(ElemType *arr,int low,int high)
{
    if(low < high)
    {
        int pivot = Partition(arr,low,high);
        QuickSort(arr,low,pivot-1);//快速排序前一半部分
        QuickSort(arr,pivot+1,high);//快速排序后一半部分
    }
}

//插入排序
void InsertSort(ElemType *arr,int n)
{
    int j;
    ElemType insertVal;//用来存储插入的值
    for(int i=1;i<n;i++)
    {
        insertVal = arr[i];
        for(j=i-1;j>=0&&arr[j]>insertVal;j--)
            arr[j+1] = arr[j];
        arr[j+1] = insertVal;
    }
}

int main() {
    SSTable ST;
    ST_Init(ST, 10);
    for (int i = 0; i < 10; i++)
        scanf("%d", &ST.elem[i]);
    BubbleSort(ST.elem, 10);//冒泡排序
    ST_Print(ST);
    QuickSort(ST.elem, 0, 9);//快速排序
    ST_Print(ST);
    InsertSort(ST.elem, 9);//快速排序
    ST_Print(ST);
    return 0;
}