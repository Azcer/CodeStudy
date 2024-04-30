#include <stdio.h>
int main()
{
    int m,n;
    printf("输输入范围:");
    scanf("%d %d",&m,&n);
    printf("范围内的奇数为:");
    for(int i=m;i<=n;i++)
    {
        if(i%2!=0)printf("%d ",i);
    }
    printf("\n范围内的偶数为:");
    for (int i = m; i <= n; i++)
    {
        if(i%2==0)printf("%d ",i);
    }
    return 0;
}