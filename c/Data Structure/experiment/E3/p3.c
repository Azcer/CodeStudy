/*

假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。其中，输入第1行给出两个正整数，分别表示社交网络图的结点数N、边数M。随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到N编号）。输出与结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。

样例输入与输出：

10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10

输出样例：每行格式(编号: xx.xx%)

1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVertexNum 100 // 最大定点数

// 创建图结构
typedef struct GNode
{
    int Nv; // 定点数
    int Ne; // 边数
    int G[MaxVertexNum][MaxVertexNum];
} GNode;
typedef GNode *Graph;

// 定义边
typedef struct ENode
{
    int v1, v2;
} ENode;
typedef ENode *Edge;

// 初始化图
Graph initGraph(int VertexNum)
{
    int v, w;
    Graph G;

    G = (Graph)malloc(sizeof(GNode));
    G->Nv = VertexNum;
    G->Ne = 0;

    for (v = 0; v < G->Nv; v++)
    {
        for (w = 0; w < G->Nv; w++)
        {
            G->G[v][w] = 0;
        }
    }

    return G;
}

// 插入边
void InsertEdge(Graph G, Edge E)
{
    G->G[E->v1][E->v2] = 1;
    G->G[E->v2][E->v1] = 1; // 双向图
}

// 创建图
Graph BuildGraph()
{
    Graph G;
    Edge E = (Edge)malloc(sizeof(ENode));

    int Nv;
    scanf("%d", &Nv); // 读入顶点个数
    G = initGraph(Nv);

    scanf("%d", &G->Ne);
    for (int i = 0; i < G->Ne; i++)
    {
        scanf("%d %d", &E->v1, &E->v2);
        E->v1--;
        E->v2--; // 输入是从1开始的
        InsertEdge(G, E);
    }

    return G;
}

// 队列
typedef int ElementType;
typedef struct QNode
{
    ElementType *data;
    int front, rear; /*头指针和尾指针*/
    int MaxSize;     /*队列最大容量*/
} QNode;
typedef QNode *Queue;

Queue CreateQueue(int MaxSize) // 创建队列
{
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
    Q->front = Q->rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFullQueue(Queue Q) // 判断队列是否满
{
    return ((Q->rear + 1) % Q->MaxSize == Q->front);
}

bool AddQ(Queue Q, ElementType x) // 入队
{
    if (IsFullQueue(Q))
    {
        printf("队列满\n");
        return false;
    }
    else
    {
        Q->rear = (Q->rear + 1) % Q->MaxSize;
        Q->data[Q->rear] = x;
        return true;
    }
}

bool IsEmptyQueue(Queue Q) // 判断队列是否为空
{
    return (Q->front == Q->rear);
}

ElementType DeleteQ(Queue Q) // 出队
{
    if (IsEmptyQueue(Q))
    {
        printf("队列空！\n");
    }
    else
    {
        Q->front = (Q->front + 1) % Q->MaxSize;
        return Q->data[Q->front];
    }
}

void BFS(Graph G, int x) // 传入图和当前位置
{
    int dist[G->Nv];                // 储存各顶点到指定顶点的距离
    for (int i = 0; i < G->Nv; i++) // 初始化数组
    {
        dist[i] = -1; // 当顶点的距离为-1时说明没有访问过
    }
    Queue Q = CreateQueue(G->Nv); // 创建队列

    dist[x] = 0;
    AddQ(Q, x);
    while (!IsEmptyQueue(Q))
    {
        int v = DeleteQ(Q);
        for (int w = 0; w < G->Nv; w++)
        {
            if (G->G[v][w] == 1 && dist[w] == -1)
            {
                dist[w] = dist[v] + 1;
                AddQ(Q, w);
            }
        }
    }

    // 统计
    int cnt = 0;
    for (int i = 0; i < G->Nv; i++)
        if (dist[i] <= 6)
            cnt++;
    printf("%d: %.2lf%%\n", x + 1, ((cnt * 1.0) / G->Nv) * 100); // 注意顶点的序号要+1
}

int main()
{
    Graph G = BuildGraph();
    for (int i = 0; i < G->Nv; i++)
    {
        BFS(G, i);
    }
    return 0;
}