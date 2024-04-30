#include <stdio.h>
int main()
{
    int ch;
    printf("请输入字符\n");
    while((ch=getchar())!=EOF)
    {
        putchar(ch);
    }
    printf("EOF\n");
    return 0;
}