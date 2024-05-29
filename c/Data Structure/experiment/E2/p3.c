/*

给定一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

输入样例1：

输入：2 1 3 0 0 0 0

输出：True



输入样例2：

输入：5 1 4 0 0 3 6 0 0 0 0

输出：False
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

// 判断是否为有效的二叉搜索树,由于BST中序遍历一定是按从小到大的顺序排列的重要检查这是否成立即可

int a[100], i = 0;
void InorderTraversal(BinTree BT) // 中序遍历二叉树
{
    if (BT)
    {
        InorderTraversal(BT->left);
        a[i++] = BT->data;
        InorderTraversal(BT->right);
    }
}

void judge(BinTree BT)
{
    InorderTraversal(BT);
    int flag = 1, j = 0;
    while (j + 1 < 100)
    {
        if (a[j + 1] == 0)
            break;
        if (a[j] >= a[j + 1])
            flag = 0;
        j++;
    }
    if (flag)
        printf("True\n");
    else
    {
        printf("False\n");
    }
}

int main()
{
    BinTree BT = CreateBinTree();
    judge(BT);
    return 0;
}