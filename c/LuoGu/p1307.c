#include <stdio.h>
#include <string.h>
char N[1000000000];

int main()
{
    scanf("%s",N);
    int len=strlen(N);
    int flag=0;//判断值
    if (N[0]=='-')//判断负数
    {
        printf("-");
    }
    for (int i = len-1; i >= 1; i--)//反向输出
    {
        if (N[i]!='0')//保证输出的结果第一位不为0
        {
            flag=1;
        }
        if(flag==1)
        printf("%c",N[i]);
    }
    if (N[0]!='-')//单出判断输出第一个数
    {
        printf("%c",N[0]);
    }
    return 0;
}