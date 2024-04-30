#include<stdio.h>

int main()
{
    int a[1000],arr[1000],n;
    printf("你需要存入几个数:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n-1,j=0;i>=0,j<n;i--,j++)
    {
        arr[i]=a[j];
    }
    return 0;
}