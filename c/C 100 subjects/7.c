#include <stdio.h>
int main()
{
    printf("输入两个数：");
    double a,b;
    scanf("%lf %lf",&a,&b);
    printf("%lf*%lf=%.2lf",a,b,a*b);
    return 0;
}