#include <stdio.h>
#define N 10
typedef int ElemType;

void Merge(ElemType *a,int low,int mid,int high)
{
    static ElemType b[N];
    int i,j,k;
    for(int i=low;i<=high;i++)
        b[i] = a[i];
    k = low;
    for(i=low,j=mid+1;i<=mid && j<=high;)
    {
        if(b[i]<b[j])
        {
            a[k] = b[i];
            k++;
            i++;
        }else{
            a[k] = b[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        a[k] = b[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        a[k] = b[j];
        k++;
        j++;
    }
}

void MergeSort(ElemType *a,int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}

void print(ElemType *arr)
{
    for(int i=0;i<N;i++)
        printf("%3d",arr[i]);
    printf("\n");
}

int main()
{
    ElemType arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    MergeSort(arr,0,N-1);//归并排序
    print(arr);
}
