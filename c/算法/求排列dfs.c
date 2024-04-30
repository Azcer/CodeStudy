// 用dfs求排列
#include <stdio.h>
int box[100], book[100], n;
void dfs(int step)
{
    if (step > n) // 终止条件
    {
        for (int i = 1; i <= n; i++)
            printf("%d ", box[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (book[i] == 0) // 递归条件
        {
            box[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return;
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}
