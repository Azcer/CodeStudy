#include <stdio.h>
int main()
{
    int k,flag=0;//flag为标记
    scanf("%d",&k);
    int sub1,sub2,sub3;
    for(int i=10000;i<=30000;i++)//遍历
    {
        int a=i;
        sub1=a/100;
        sub2=(a%10000)/10;
        sub3=a%1000;
        if (sub1%k==0&&sub2%k==0&&sub3%k==0)
        {
            printf("%d\n",a);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("No\n");
    }
    
    return 0;
}