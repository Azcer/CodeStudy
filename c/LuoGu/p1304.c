#include <stdio.h>
int f(int n);

int main()
{
    int N; // 正偶数
    scanf("%d", &N);
    for (int i = 4; i <= N; i += 2) // 遍历4~N的所有偶数
    {
        int flag = 0;                    // 标记值
        for (int j = 2; j <= i - 1; j++) // 找到第一个质数
        {
            if (!f(j)) // 如果不是质数就跳过
            {
                continue;
            }

            for (int k = j; k <= i - 1; k++) // 找到第二个质数
            {
                if (!f(k)) // 如果不是质数就跳过
                {
                    continue;
                }
                if (i == (j + k)) // 判断是否符合题意
                {
                    printf("%d=%d+%d\n", i, j, k);
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                break; // 保证只输出一组
            }
        }
    }
    return 0;
}

int f(int n) // 判断一个数是否是质数,是返回1，不是返回0
{
    int flag = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}