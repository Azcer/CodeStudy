#include <stdio.h>
int main()
{
    int k,n=1;
    double s=0;
    scanf("%d",&k);
    do
    {
        s+=(1.0/n);
        n++;
    } while (s<=k);
    printf("%d\n",n-1);
    return 0;
}