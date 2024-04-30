#include <stdio.h>
void swap(int *a,int *b);
int main()
{
    printf("输入两个数:");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("a=%d,b=%d交换后\n",a,b);
    swap(&a,&b);
    printf("a=%d\nb=%d",a,b);
    return 0;
}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}