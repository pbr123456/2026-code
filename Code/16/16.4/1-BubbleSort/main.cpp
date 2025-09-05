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

//冒泡排序,两层循环
void BubbleSort(ElemType *elem,int len)
{
//    for(int i=0;i<len;i++)
//        for(int j=i;j<len;j++)
//            if(elem[j] > elem[j+1])
//            {
//                int temp = elem[j];
//                elem[j] = elem[j+1];
//                elem[j+1] = temp;
//            }
        int i,j;
        bool flag;
        for(i=0;i<len-1;i++)//控制的是有序数的数目
        {
            flag = false;
            for(j=len-1;j>i;j--)//内层比较交换
                if(elem[j-1]>elem[j])
                {
                    flag = true;
                    swap(elem[j-1],elem[j]);
                }
            if(flag == false)//如果一趟比较没有发生任何交换，说明有序，提前结束
                return;
        }
}

int main()
{
    SSTable ST;
    ST_Init(ST,10);
//    //为了方便调试，才设置A数组
//    ElemType A[10] = {64,94,95,79,69,84,18,22,12,78};
//    //内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy，不能用strcpy
//    memcpy(ST.elem,A, sizeof(A));
    ST_Print(ST);//随机后的数组打印
    BubbleSort(ST.elem,10);//冒泡排序
    ST_Print(ST);//排序后的数组打印
}