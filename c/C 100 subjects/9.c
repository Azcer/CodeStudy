#include <stdio.h>
int main()
{
    printf("输入相除的两个数:");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d除以%d的商为:%d\n",a,b,a/b);
    printf("%d除以%d的余数为:%d",a,b,a%b);
    return 0;
}