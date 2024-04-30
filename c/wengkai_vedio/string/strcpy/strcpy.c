#include <stdio.h>
#include <string.h>

int main()
{
    char a[]="Hello World!";
    char b[strlen(a)+1];
    strcpy(b,a);
    for(int i=0;i<strlen(a);i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    for(int i=0;i<strlen(a);i++)
    {
        printf("%c",b[i]);
    }
    return 0;
}