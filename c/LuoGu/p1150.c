#include <stdio.h>
int main()
{
    int n,k,sum=0,t=0;//t为烟蒂的数量
    scanf("%d %d",&n,&k);
    sum+=n;
    t+=n;
    while(t>=k)
    {
        n=t/k;
        t-=n*k;
        sum+=n;
        t+=n;
    }
    printf("%d",sum);
    
}