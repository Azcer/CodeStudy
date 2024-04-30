#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
} TNode;
typedef TNode *BinTree;
typedef BinTree ElementType;

typedef struct QNode
{
    ElementType *data;
    int front, rear; /*头指针和尾指针*/
    int MaxSize;     /*队列最大容量*/
} QNode;
typedef QNode *Queue;

typedef struct SNode
{
    ElementType *Data; // 存储元素的数组
    int top;           // 栈顶
    int MaxSize;       // 堆栈最大容量
} SNode;
typedef SNode *Stack;

// 有关堆栈的函数
//  生成空堆栈，其最大长度为MaxSize
Stack CreateStack(int MaxSize)
{
    Stack s = (Stack)malloc(sizeof(SNode));
    s->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    s->top = -1;
    s->MaxSize = MaxSize;
    return s;
}

// 判断堆栈s是否已满
bool IsFullStack(Stack s)
{
    return (s->top == s->MaxSize - 1);
}

// 判断堆栈s是否空
bool IsEmptyStack(Stack s)
{
    return (s->top == -1);
}

// 入栈
bool Push(Stack s, ElementType x)
{
    if (IsFullStack(s))
    {
        printf("堆栈已满");
        return false;
    }
    else
    {
        s->Data[++(s->top)] = x;
        return true;
    }
}

// 出栈
ElementType Pop(Stack s)
{
    if (IsEmptyStack(s))
    {
        printf("堆栈空\n");
    }
    else
    {
        return s->Data[(s->top)--];
    }
}

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

// 有关树的函数
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

void InorderTraversal(BinTree BT) // 中序遍历二叉树
{
    if (BT)
    {
        InorderTraversal(BT->left);
        printf("%d ", BT->data);
        InorderTraversal(BT->right);
    }
}

void PreorderTraversal(BinTree BT) // 先序遍历二叉树
{
    if (BT)
    {
        printf("%d ", BT->data);
        InorderTraversal(BT->left);
        InorderTraversal(BT->right);
    }
}

void PostorderTraversal(BinTree BT) // 后续遍历二叉树
{
    if (BT)
    {
        InorderTraversal(BT->left);
        InorderTraversal(BT->right);
        printf("%d ", BT->data);
    }
}

void InorderStackTraversal(BinTree BT) // 用堆栈进行中序遍历二叉树
{
    BinTree T;
    Stack S = CreateStack(100);
    T = BT;
    while (T || !IsEmptyStack(S))
    {
        while (T)
        {
            Push(S, T);
            T = T->left;
        }
        T = Pop(S);
        printf("%d ", T->data);
        T = T->right;
    }
}

void LevelorderTraversal(BinTree BT) // 层序遍历二叉树
{
    Queue Q;
    BinTree T;
    if (!BT)
        return;
    Q = CreateQueue(100);
    AddQ(Q, BT);
    while (!IsEmptyQueue(Q))
    {
        T = DeleteQ(Q);
        printf("%d ", T->data);
        if (T->left)
            AddQ(Q, T->left);
        if (T->right)
            AddQ(Q, T->right);
    }
}

int GetHeight(BinTree BT) // 求二叉树的高
{
    int HL, HR, MaxH; // HL左子树的高，HR为右子树的高，MaxH为树高

    if (BT)
    {
        HL = GetHeight(BT->left);
        HR = GetHeight(BT->right);
        MaxH = HL > HR ? HL : HR;
        return (MaxH + 1);
    }
    else
        return 0;
}

void PreorderPrintLeaves(BinTree BT) // 先序遍历二叉树的叶子节点
{
    if (BT)
    {
        if (!BT->left && !BT->right)
            printf("%d ", BT->data);
        PreorderPrintLeaves(BT->left);
        PreorderPrintLeaves(BT->right);
    }
}

// 二叉搜索树
BinTree Find(BinTree BST, int x) // 查找元素
{
    while (BST)
    {
        if (BST->data > x)
        {
            BST = BST->left;
        }
        else if (BST->data < x)
        {
            BST = BST->right;
        }
        else
        {
            break;
        }
    }
    return BST;
}

BinTree FindMin(BinTree BST) // 查找最小元素
{
    while (BST->left)
    {
        BST = BST->left;
    }
    return BST;
}

BinTree FindMax(BinTree BST) // 查找最大元素
{
    while (BST->right)
    {
        BST = BST->right;
    }
    return BST;
}

BinTree InsertBST(BinTree BST, int x) // 插入元素
{
    if (!BST)
    {
        BST = (BinTree)malloc(sizeof(TNode));
        BST->left = BST->right = NULL;
        BST->data = x;
    }
    else
    {
        if (x < BST->data)
        {
            BST->left = InsertBST(BST->left, x);
        }
        else if (x > BST->data)
        {
            BST->right = InsertBST(BST->right, x);
        }
    }
    return BST;
}

BinTree DeleteBST(BinTree BST, int x)
{
    BinTree tmp;
    if (!BST)
    {
        printf("未找到要删除的元素\n");
    }
    else
    {
        if (x < BST->data)
        {
            BST->left = DeleteBST(BST->left, x);
        }
        else if (x > BST->data)
        {
            BST->right = DeleteBST(BST->right, x);
        }
        else
        {
            if (BST->left && BST->right)
            {
                tmp = FindMin(BST->right);
                BST->data = tmp->data;
                BST->right = DeleteBST(BST->right, tmp->data);
            }
            else
            {
                tmp = BST;
                if (!BST->left)
                {
                    BST = BST->right;
                }
                else
                {
                    BST = BST->left;
                }
                free(tmp);
            }
        }
    }
    return BST;
}