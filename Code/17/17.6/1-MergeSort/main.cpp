#include <stdio.h>
#include <stdlib.h>

#define N 7
typedef int ElemType;

//实现合并两个有序数组
void Merge(ElemType *A,int low,int mid,int high)
{
    static ElemType B[N];//加static的目的是无论递归调用多少次，都只有一个B[N]
    int i,j,k;
    for(int i=low;i<=high;i++)
        B[i] = A[i];//把A[i]的值全赋给B[i]
    k=low;
    for(i=low,j=mid+1;i<=mid && j<=high;)//合并两个数组
    {
        if(B[i]<B[j])
        {
            A[k] = B[i];
            i++;
            k++;
        }else{
            A[k] = B[j];
            j++;
            k++;
        }
    }
    //把某一个有序数组中剩余的元素放进来
    while(i<=mid)
    {
        A[k] = B[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        A[k] = B[j];
        j++;
        k++;
    }
}

//归并排序
void MergeSort(ElemType *A,int low,int high)//递归分割
{
    if(low < high)
    {
        int mid = (low+high)/2;
        MergeSort(A,low,mid);//排序好前一半
        MergeSort(A,mid+1,high);//排序好后一半
        Merge(A,low,mid,high);//将两个排序好的数组合并
    }
}

//打印数组
void print(ElemType *A)
{
    for(int i=0;i<N;i++)
        printf("%3d",A[i]);
    printf("\n");
}

int main() {
    ElemType A[N] = {49,38,65,97,76,13,27};
    MergeSort(A,0,6);//归并排序
    print(A);
    return 0;
}
