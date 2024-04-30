#include <stdio.h>
int main()
{
    int n, m, a[7], flag = 0; // n为学校的时间，m为课外班时间
    // 输入并记录上课总时间
    for (int i = 0; i < 7; i++)
    {
        scanf("%d %d", &n, &m);
        a[i] = n + m;
    }
    for (int i = 0; i < 7; i++)
    {
        if (a[i] > 8)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("%d\n", 0);
    }
    else
    { // 找到最大值的角标
        int max = 0, t;
        for (int i = 0; i < 7; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
                t = i;
            }
        }
        printf("%d\n", t + 1);
    }
    return 0;
}