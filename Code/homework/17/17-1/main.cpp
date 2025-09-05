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

//选择排序
void SelectSort(ElemType *arr,int len)
{
    int j;
    for(int i=0;i<len;i++)
    {
        int min = i;
        for(j=i+1;j<len;j++)
            if(arr[j]<arr[min])
                min = j;
        if(min != j)
            swap(arr[min],arr[i]);
    }
}

void AjustDown(ElemType *arr,int k,int len)
{
    int dad = k;
    int son = 2*dad+1;
    while(son<len)
    {
        while(son+1<len && arr[son]<arr[son+1])
            son++;
        if(arr[son]>arr[dad])
        {
            swap(arr[son],arr[dad]);
            dad = son;
            son = 2*dad+1;
        }else
            break;
    }
}

void HeapSort(ElemType *arr,int len)
{
    //第一步建立大根堆
    for(int i=len/2-1;i>=0;i--)
        AjustDown(arr,i,len);
    swap(arr[0],arr[len-1]);
    for(int i=len-1;i>1;i--)
    {
        AjustDown(arr,0,i);//调整剩余的无序数组
        swap(arr[0],arr[i-1]);
    }
}

//选择排序，堆排序
int main() {
    SSTable ST;
    ST_Init(ST, 10);
    for(int i=0;i<10;i++)
        scanf("%d",&ST.elem[i]);
    SelectSort(ST.elem, 10);//选择排序
    ST_Print(ST);
    HeapSort(ST.elem,10);//堆排序
    ST_Print(ST);
    return 0;
}