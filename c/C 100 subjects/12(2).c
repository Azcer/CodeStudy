#include<stdio.h>
int main()
{
    int a,b;
    printf("输入a,b:");
    scanf("%d %d",&a,&b);
    printf("a=%d,b=%d交换后\n",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("a=%d\nb=%d",a,b);
    return 0;
}