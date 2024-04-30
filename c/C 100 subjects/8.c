#include<stdio.h>
int main()
{
    printf("请输入一个字符：");
    char a;
    scanf("%s",&a);
    printf("%c的ASCII码为:%d",a,a);
    return 0;
}