#include <stdio.h>
int main()
{
    printf("输入三个数:");
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>=b&&a>=c)
    {
        printf("%d最大",a);
    }else if (b>=a&&b>=c)
    {
        printf("%d最大",b);
    }else if (c>=b&&c>=a)
    {
        printf("%d最大",c);
    }
    return 0;
    
}