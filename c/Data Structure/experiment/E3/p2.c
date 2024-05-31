/*
利用邻接表存储有向图，编写程序实现对图的深度优先遍历。输入第一行为结点个数，第二行为结点的数据，第三行开始为边的信息。输出深度优先遍历(从第一个节点开始)结果。
输入样例：

6

a b c d e f

a b

a c

a e

b e

e d

d f

e f

输出：

a b e d f c
*/
#include <stdio.h>
// 查找函数
int Find(char a[], int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == c)
        {
            return i;
        }
    }
    printf("未找到元素\n");
    return -1;
}

// DFS函数
int visitied[101] = {0};
void DFS(int len, char vertex[], int edge[][len], int n) // 传入长度，顶点，边，所在位置
{
    visitied[n] = 1;
    printf("%c ", vertex[n]);
    for (int i = 0; i < len; i++)
    {
        if (edge[n][i] == 1 && visitied[i] != 1)
        {
            DFS(len, vertex, edge, i);
        }
    }
}

int main()
{
    // 创建顶点数组
    int n;
    scanf("%d", &n);
    char vertex[n];

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        scanf("%c", &vertex[i]);
    }

    // 构建边的领接表
    int edge[n][n];
    char v, w;
    for (int i = 0; i < n; i++) // 初始化
        for (int j = 0; j < n; j++)
            edge[i][j] = 0;
    fflush(stdin);
    while (scanf("%c %c", &v, &w) != EOF)
    {
        edge[Find(vertex, n, v)][Find(vertex, n, w)] = 1;
        fflush(stdin);
    }

    // DFS
    DFS(n, vertex, edge, 0);
}