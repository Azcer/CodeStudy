#include <stdio.h>
int main()
{
    printf("输入两个数:");
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<b)
    {
        printf("%d<%d",a,b);
    }else if(a==b)
    {
        printf("%d=%d",a,b);
    }else if (a>b)
    {
        printf("%d>%d",a,b);
    }
    return 0;
    
}
