#include <stdio.h>
int main() 
{
    _Bool ligt[2000000]={0};
    int n,t;
    double a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf %d",&a,&t);
        double s;
        int m;
        for (int i = 1; i <= t; i++)
        {
            s=i*a;
            m=(int)s;
            ligt[m]=1-ligt[m];
        }
    }
    for (int i = 0; i < 2000000; i++)
    {
        if(ligt[i]==1)
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}