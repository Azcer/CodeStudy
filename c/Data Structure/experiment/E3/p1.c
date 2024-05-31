/*
编写程序实现带权图的邻接矩阵存储，输出邻接矩阵。输入第一行为结点个数(节点编号从0开始)，第二行开始为边的信息(节点编号，节点编号，权重)，输出邻接矩阵。
输入样例：

6

0 1 5

0 3 7

1 2 4

2 0 8

2 5 9

3 2 5

3 5 6

4 3 5

5 0 3

5 4 1

输出样例：

0 5 0 7 0 0

0 0 4 0 0 0

8 0 0 0 0 9

0 0 5 0 0 6

0 0 0 5 0 0

3 0 0 0 1 0


*/
#include <stdio.h>
int main()
{
    int n, v, w, weight;
    scanf("%d", &n);
    int g[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = 0;
    while (scanf("%d %d %d", &v, &w, &weight) != EOF)
    {
        g[v][w] = weight;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}
