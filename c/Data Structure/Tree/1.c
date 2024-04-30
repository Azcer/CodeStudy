#include <stdio.h>
int main()
{
    int L, cnt = 0, sum = 0, flag = 1;
    scanf("%d", &L);
    for (int i = 2; i < 10000; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            sum += i;

            if (sum <= L)
            {
                cnt++;
                printf("%d ", i);
            }
            else
            {
                printf("\n");
                break;
            }
        }
        flag = 1;
    }
    printf("count = %d", cnt);
    return 0;
}
