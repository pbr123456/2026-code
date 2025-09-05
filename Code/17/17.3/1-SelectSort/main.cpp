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
    for(int i=0;i<len-1;i++)
    {
        int min = i;//首先认为i位置的元素最小
        for(int j=i+1;j<len;j++)
            if(arr[min]>arr[j])//当某个元素arr[j]小于最小元素
                min = j;//将下标j赋值给min，min就记录下来了最小值的下标
        if(min != i)
            swap(arr[min],arr[i]);
    }
}

//选择排序
int main() {
    SSTable ST;
    ST_Init(ST, 10);
    ST_Print(ST);
    SelectSort(ST.elem, 10);//选择排序
    ST_Print(ST);
    return 0;
}