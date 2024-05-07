#include <stdio.h>
#define maxsize 1000
int main()
{
    int A[maxsize];
    int i = 0, a, sum, j, k;
    while (scanf("%d", &a) != EOF)
    {
        A[i++] = a;
    }
    scanf("%d", &sum);
    for (j = 0; j < maxsize; j++)
    {
        for (k = j + 1; k < maxsize; k++)
        {
            if ((A[j] + A[k] == sum))
            {
                printf("%d %d\n", j, k);
                break;
            }
        }
        if (A[j] + A[k] == sum)
            break;
    }
    return 0;
}
