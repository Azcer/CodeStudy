/*
给定一个二叉树， 编写算法计算二叉树中任意两个结点的公共祖先。
其中，输入第一行为二叉树序列，第二行和第三行分别为两个节点数据；
输出：两个节点的公共祖先（最近的父节点）

输入样例1：

输入：

3 5 1 6 2 0 8 0 0 7 4 0 0 0 0 0 0

5

1

输出: 3



输入样例2：

输入:

3 5 1 6 2 0 8 0 0 7 4 0 0 0 0 0 0

5

4

输出: 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义二叉树
typedef struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
} TNode;
typedef TNode *BinTree;
typedef BinTree ElementType;

// 定义队列
typedef struct QNode
{
    ElementType *data;
    int front, rear; /*头指针和尾指针*/
    int MaxSize;     /*队列最大容量*/
} QNode;
typedef QNode *Queue;

// 有关队列的函数
Queue CreateQueue(int MaxSize) // 创建队列
{
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->data = (ElementType *)malloc(sizeof(TNode) * MaxSize);
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

// 层序创建二叉树
BinTree CreateBinTree() // 创建二叉树
{
    int data;
    BinTree BT, T;
    Queue Q = CreateQueue(100); // 创建空队列
    scanf("%d", &data);
    if (data != 0)
    {
        BT = (BinTree)malloc(sizeof(TNode));
        BT->data = data;
        BT->left = BT->right = NULL;
        AddQ(Q, BT);
    }
    else
        return NULL;
    while (!IsEmptyQueue(Q))
    {
        T = DeleteQ(Q);
        scanf("%d", &data);
        if (data == 0)
            T->left = NULL;
        else
        {
            T->left = (BinTree)malloc(sizeof(TNode));
            T->left->data = data;
            T->left->left = T->left->right = NULL;
            AddQ(Q, T->left);
        }
        scanf("%d", &data);
        if (data == 0)
            T->right = NULL;
        else
        {
            T->right = (BinTree)malloc(sizeof(TNode));
            T->right->data = data;
            T->right->left = T->right->right = NULL;
            AddQ(Q, T->right);
        }
    }
    return BT;
}

// 判断节点是否在子树中
int containsNode(BinTree BT, int x)
{
    if (!BT)
    {
        return 0;
    }
    else
    {
        if (BT->data == x)
        {
            return 1;
        }
        else
        {
            return (containsNode(BT->left, x) || containsNode(BT->right, x));
        }
    }
}

// 找到共同的祖先节点

TNode *FindCommonAncestor(BinTree BT, int x1, int x2)
{
    if (!BT)
    {
        return NULL;
    }
    else
    {
        if (containsNode(BT->left, x1) && containsNode(BT->left, x2))
        {
            return FindCommonAncestor(BT->left, x1, x2);
        }
        else if (containsNode(BT->right, x1) && containsNode(BT->right, x2))
        {
            return FindCommonAncestor(BT->right, x1, x2);
        }
        else
        {
            return BT;
        }
    }
}

int main()
{
    BinTree BT = CreateBinTree();
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    BinTree CommonAncestor = FindCommonAncestor(BT, x1, x2);
    printf("%d\n", CommonAncestor->data);
    return 0;
}