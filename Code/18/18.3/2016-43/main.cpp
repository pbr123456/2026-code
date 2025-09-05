#include <stdio.h>
#include <stdlib.h>

int setParitition(int a[],int n)
{
    int pivotkey,low=0,low0=0,high=n-1,high0=n-1,flag=1,k=n/2,i;
    int s1=0,s2=0;
    while(flag)//当low等于n/2-1时，flag=0，这个分割循环就结束
    {
        pivotkey = a[low];//选择枢纽
        while(low < high) //基于枢纽对数据进行划分
        {
            while(low < high && a[high] >= pivotkey)
                high--;
            if(low != high)
                a[low] = a[high];
            while(low < high && a[low] <= pivotkey)
                low++;
            if(low != high)
                a[high] = a[low];
        }
        a[low] = pivotkey;//把分割值放到对应的位置
        if(low == k-1)//如果枢纽是n/2个元素，则划分好，由于数组的下标从0开始
            flag = 0;
        else{ //是否继续划分
            if(low < k-1)
            {
                low0 = ++low;//low0只是做暂存
                high = high0;//把上次暂存的high0拿过来
            }else
            {
                low = low0;//把上次暂存的low0拿过来
                high0 = --high;//high0只是做暂存，为下一次使用做准备
            }
        }
    }
    for(i=0;i<k;i++)
        s1 += a[i];
    for(i=k;i<n;i++)
        s2 += a[i];
    return s2-s1;
}

int main()
{
    int A[10] = {4,1,12,18,7,13,18,16,5,15};
    int difference;
    difference = setParitition(A,10);
    printf("%d\n",difference);
    return 0;
}
