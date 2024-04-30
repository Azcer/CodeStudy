#include <stdio.h>
int main()
{
    char a[10]={0},b[10]={0};//a为彗星名字，b为队伍名字
    int m=1,n=1;//m为彗星名字转化为的数字，n为队伍名字转化为的数字
    scanf("%s",a);
    scanf("%s",b);
    for (int i = 0; i < 6; i++)
    {
        if (a[i]!=0)
        {
        m*=a[i]-64;
        }
        if(b[i]!=0)
        {
        n*=b[i]-64;
        }
    }
    if ((m%47)==(n%47))
    {
        printf("GO\n");
    }else
    {
        printf("STAY\n");
    }
    return 0;
    
}