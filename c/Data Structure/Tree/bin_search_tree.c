#include <stdio.h>
#include "tree.h"

int main()
{
    int x;
    BinTree BST = NULL;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &x);
        BST = InsertBST(BST, x);
    }
    BST = DeleteBST(BST, 3);
    InorderStackTraversal(BST);
    printf("最大值:%d 最小值:%d", FindMax(BST)->data, FindMin(BST)->data);
    return 0;
}