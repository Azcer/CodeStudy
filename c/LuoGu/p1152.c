#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];//创建数组
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int b[n-1];//创建结果数组
    for (int i = 0; i < n-1; i++)
    {
        b[i]=abs(a[i+1]-a[i]);
    }
    for (int i = 0; i < n-2; i++)//排序结果数组
    {
        for (int j = 0; j < n-2-i; j++)
        {
            if (b[j]>b[j+1])
            {
                int t;
                t=b[j+1];
                b[j+1]=b[j];
                b[j]=t;
            }
        }
    }
    int c[n-1];//创建判断数组
    for (int i = 0; i < n-1; i++)
    {
        c[i]=i+1;
    }
    //判断
    int flag=1;
    for (int i = 0; i < n-1; i++)
    {
        if (b[i]!=c[i])
        {
            flag=0;
            break;
        }
        
    }
    if (flag)
    {
        printf("Jolly\n");
    }else
    {
        printf("Not jolly\n");
    }
    return 0;
}