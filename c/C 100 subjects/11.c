#include<stdio.h>
int main()
{
    int a;
    float b;
    double c;
    char d;
    long e;
    long long f;
    long double g;
    printf("int:%d\n",sizeof(a));
    printf("float:%d\n",sizeof(b));
    printf("double:%d\n",sizeof(c));
    printf("char:%d\n",sizeof(d));
    printf("long:%d\n",sizeof(e));
    printf("long long:%d\n",sizeof(f));
    printf("long double:%d\n",sizeof(g));
    return 0;
}