#include <stdio.h>
int main()
{
    int a,b;
    printf("输入a,b:");
    scanf("%d %d",&a,&b);
    printf("a=%d,b=%d交换后\n",a,b);
    int c;
    c=b;
    b=a;
    a=c;
    printf("a=%d\nb=%d",a,b);
}