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
    for(int i=0;i<10;i++)
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

//把某个子树调整为大根堆
void AjustDown(ElemType *arr,int k,int len)
{
    int dad = k;//父亲的下标
    int son = 2*dad+1;//左孩子的下标
    while(son<=len)
    {
        if(son+1<=len && arr[son]<arr[son+1])//如果左孩子小于右孩子
            son++;//拿右孩子
        if(arr[son]>arr[dad])//如果孩子大于父亲
        {
            swap(arr[son],arr[dad]);//交换
            dad = son;//son重新作为dad，去判断子树是否符合大根堆
            son = 2*dad+1;
        }else
            break;
    }
}

//堆排序
void HeapSort(ElemType *arr,int len)
{
    int i;
    //第一步就是建立大根堆
    for(i=len/2;i>=0;i--)
        AjustDown(arr,i,len);
    for(i=10;i<10000;i++)
    {
        if(arr[i] < arr[0])
        {
            arr[0] = arr[i];
            AjustDown(arr,0,9);
        }
    }
}

//2022年42题
int main() {
    SSTable ST;
    ST_Init(ST, 10000);
    HeapSort(ST.elem, 9);//堆排序,所有元素都参与排序
    ST_Print(ST);
    return 0;
}