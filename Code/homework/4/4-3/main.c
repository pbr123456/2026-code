#include <stdio.h>

int main() {
    int ans=0,money=100;
    for(int i=1;i<=40;i++)
        for(int j=1;j<=40;j++)
            for(int k=1;k<=40;k++)
                for(int l=1;l<=40;l++)
                    if(i+j+k+l == 40 && i*10+j*5+k*2+l*1 == 100)
                        ans += 1;
    printf("%d",ans);
    return 0;
}
