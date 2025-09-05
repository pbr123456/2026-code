#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType *elem;//整形指针，申请堆空间的起始地址存入elem
    int TableLen;//存储动态数组里边元素的个数
}SSTable;

//Init进行了随机数生成
void ST_Init(SSTable &ST,int len)
{
    ST.TableLen = len;
    ST.elem = (ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));//随机数生成
    for(i=0;i<ST.TableLen;i++)
        ST.elem[i] = rand() % 100;//为了随机生成的数都在0到99之间

}

//打印顺序表
void ST_print(SSTable ST)
{
    int i;
    for(i=0;i<ST.TableLen;i++)
        printf("%3d",ST.elem[i]);
    printf("\n");
}

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

//函数名中存储的是函数的入口地址，也是一个指针，是函数指针类型
//left指针和right指针是指向数组中的任意两个元素
//qsort规定如果left指针指向的值大于right指针指向的值，返回正值，小于返回负值，相等返回0
int compare(const void *left,const void *right)
{
    return *(int*)left - *(int*)right;
}

//折半查找
int main() {
    SSTable ST;
    ElemType key;
    int pos;//存储查询元素的位置
    ST_Init(ST,10);
    ST_print(ST);
    qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);//排序
    ST_print(ST);
    printf("please input search key:\n");
    scanf("%d",&key);
    pos = BinarySearch(ST,key);
    if(pos!=-1)
        printf("find key,pos=%d\n",pos);
    else
        printf("not find\n");
    return 0;
}
