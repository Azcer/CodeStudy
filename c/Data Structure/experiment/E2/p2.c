/*
给定一棵二叉搜索树，请 按中序遍历将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
输入样例：5 3 6 2 4 0 8 1 0 0 0 7 9

输出样例：1 null 2 null 3 null 4 null 5 null 6 null 7 null 8 null 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int a[100] = {0}, i = 0;
// 创建树结构体
typedef struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
} TNode;
typedef TNode *BinTree;

// 插入元素
BinTree InsertBST(BinTree BST, int x)
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

void InorderTraversal(BinTree BT)
{
    if (BT)
    {
        InorderTraversal(BT->left);
        a[i++] = BT->data;
        InorderTraversal(BT->right);
    }
}
BinTree transform(int *b)
{
    BinTree BST = NULL;
    for (int j = 0; j < 100; j++)
    {
        if (b[j] != 0)
        {
            BST = InsertBST(BST, b[j]);
        }
        else
        {
            break;
        }
    }
    return BST;
}

int main()
{
    int x;
    BinTree BST = NULL, T = NULL;
    while (scanf("%d", &x) != EOF)
    {
        if (x == 0)
            continue;
        else
            BST = InsertBST(BST, x);
    }
    InorderTraversal(BST);
    T = transform(a);
    while (T)
    {
        printf("%d ", T->data);
        if (T->right)
        {
            printf("null ");
        }
        T = T->right;
    }
    return 0;
}