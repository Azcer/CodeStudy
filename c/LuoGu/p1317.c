#include <stdio.h>
int main()
{
    int n, flag = 0, cnt = 0; // flag为标记值，如果有向下的数据走向就为1；cnt为计数
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
        {
            flag = 1;
        }
        if (flag) // 在向下的条件下再找一个向上的即可
        {
            if (a[i + 1] > a[i])
            {
                cnt++;
                flag = 0; // 重置
            }
        }
    }
    printf("%d", cnt);
    return 0;
}