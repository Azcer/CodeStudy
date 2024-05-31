/*
编写程序计算从“0”结点到其他结点的最短距离。
*/

#include <stdio.h>
#include <stdlib.h>

// 构建图
// 定义图的结构体
typedef struct GraphNode
{
    int Nv;          // 定点数
    int Ne;          // 边数
    int G[101][101]; // 边的权重
} GraphNode;
typedef GraphNode *Graph;

// 通过题目定制图

// 插入边
void InsertEdge(Graph G, int v, int w, int weight)
{
    G->G[v][w] = weight;
    G->G[w][v] = weight;
}

// 构建图
Graph BuiltGraph()
{
    Graph G = (Graph)malloc(sizeof(GraphNode));
    G->Nv = 5;
    G->Ne = 8;
    for (int i = 0; i < G->Nv; i++)
        for (int j = 0; j < G->Nv; j++)
            G->G[i][j] = 0;
    InsertEdge(G, 0, 1, 4);
    InsertEdge(G, 0, 2, 6);
    InsertEdge(G, 0, 4, 5);
    InsertEdge(G, 1, 3, 13);
    InsertEdge(G, 1, 4, 10);
    InsertEdge(G, 2, 3, 25);
    InsertEdge(G, 2, 4, 15);
    InsertEdge(G, 3, 4, 20);
    return G;
}

// 判断是否是数组中的最小值
int IsMin(int a[], int len, int index)
{
    int min = 9999;
    for (int i = 0; i < len; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    if (a[index] == min)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Dijkstra算法
void Dijkstra(Graph G, int vertex)
{
    // 初始化数组
    int collected[G->Nv]; // 是否已经收集
    int dist[G->Nv];      // 各点到原点的距离
    int a[G->Nv];         // 辅助数组，方便收集定点时，剔除该顶点的距离
    for (int i = 0; i < G->Nv; i++)
    {
        collected[i] = 0;
        dist[i] = 9999; // 无穷大
        a[i] = 9999;
    }
    int v; // 当前所指向的顶点
    dist[vertex] = 0;
    a[vertex] = 0;
    while (1)
    {
        int flag = 0; // 标记值，判断是否找到满足条件的顶点
        for (int i = 0; i < G->Nv; i++)
        {
            if (collected[i] == 0 && IsMin(a, G->Nv, i))
            {
                v = i;
                flag = 1;
                break;
            }
        }
        if (!flag)
            break;
        collected[v] = 1;
        a[v] = 9999;
        for (int w = 0; w < G->Nv; w++)
        {
            if (G->G[v][w] != 0 && !collected[w] && dist[v] + G->G[v][w] < dist[w])
            {
                dist[w] = dist[v] + G->G[v][w];
                a[w] = dist[v] + G->G[v][w];
            }
        }
    }

    // 输出
    for (int i = 1; i < G->Nv; i++)
        printf("%d : %d\n", i, dist[i]);
}

int main()
{
    Graph G = BuiltGraph();
    Dijkstra(G, 0);
}