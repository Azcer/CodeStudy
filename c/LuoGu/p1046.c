#include <stdio.h>
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    int l,cnt=0;
    scanf("%d",&l);
    for (int i = 0 ;i < 10; i++)
    {
        if(a[i]<=l+30)cnt++;
    }
    printf("%d",cnt);
    
    return 0;
}