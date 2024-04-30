// 用dfs解决走迷宫问题
#include <stdio.h>
#include <stdlib.h>
int a[100][100]; // 地图，1表示可以走，2表示障碍
int b[100][100]; // 标记数组，0表示没走过，1表示走过
int min = 9999;
// x，y表示起始坐标，p，q表示终点坐标，step表示步数
void dfs(int x, int y, int p, int q, int step)
{
    if (x == p && y == q) // 终止条件
    {
        if (step < min)
        {
            min = step;
        }
        return;
    }
    // 四个方向进行试探    递归条件
    // 右
    if (a[x + 1][y] == 1 && b[x + 1][y] == 0)
    {
        b[x + 1][y] = 1;
        dfs(x + 1, y, p, q, step + 1);
        b[x + 1][y] = 0;
    }
    // 下
    if (a[x][y + 1] == 1 && b[x][y + 1] == 0)
    {
        b[x][y + 1] = 1;
        dfs(x, y + 1, p, q, step + 1);
        b[x][y + 1] = 0;
    }
    // 左
    if (a[x - 1][y] == 1 && b[x - 1][y] == 0)
    {
        b[x - 1][y] = 1;
        dfs(x - 1, y, p, q, step + 1);
        b[x - 1][y] = 0;
    }
    // 上
    if (a[x][y - 1] == 1 && b[x][y - 1] == 0)
    {
        b[x][y - 1] = 1;
        dfs(x, y - 1, p, q, step + 1);
        b[x][y - 1] = 0;
    }
    return;
}
int main()
{
    int n, m;
    int x, y, p, q;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    scanf("%d%d%d%d", &x, &y, &p, &q);
    dfs(x, y, p, q, 0);
    printf("%d\n", min);
    system("pause\n");
    return 0;
}
/*
输入
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
1 1 4 3

输出
7
*/