#include <stdio.h>
int f(int n);
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = n-1; i > 0; i--)
    {
        if (n%i==0&&f(i))
        {
            printf("%d",i);
            break;
        }
        
    }
    return 0;
}
int f(int n)//判断一个数是否是质数
{
    int flag=1;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)flag=0;
        break;
    }
    return flag;
}