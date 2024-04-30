#include <stdio.h>
int main()
{
    char c;
    while(scanf("%c",&c)!=EOF)
    {
    if(c=='a'||c=='o'||c=='e'||c=='i'||c=='u'||
    c=='A'||c=='O'||c=='E'||c=='I'||c=='U')
    {
        printf("元音\n");
    }else
    {
        printf("辅音\n");
    }
    }
    return 0;
}