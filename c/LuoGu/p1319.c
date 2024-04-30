#include <stdio.h>
int main()
{
    int n, sum = 0, m, flag = 0;
    scanf("%d", &n);
    int a[n * n];
    while (sum < n * n)
    {
        scanf("%d", &m);
        if (flag == 0)
        {
            for (int i = sum; i < sum + m; i++)
            {
                a[i] = 0;
            }
        }
        else if (flag == 1)
        {
            for (int i = sum; i < sum + m; i++)
            {
                a[i] = 1;
            }
        }
        flag = 1 - flag;
        sum += m;
    }
    for (int i = 0; i < n * n; i++)
    {
        printf("%d", a[i]);
        if ((i + 1) % n == 0)
        {
            printf("\n");
        }
    }
    return 0;
}