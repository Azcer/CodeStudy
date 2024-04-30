#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

int main()
{
    BinTree BT = CreateBinTree();
    printf("中序遍历:\n");
    InorderTraversal(BT);
    printf("\n");
    InorderStackTraversal(BT);
    printf("\n先序遍历:\n");
    PreorderTraversal(BT);
    printf("\n后序遍历:\n");
    PostorderTraversal(BT);
    printf("\n层序遍历:\n");
    LevelorderTraversal(BT);
    printf("\n先序遍历叶子节点:\n");
    PreorderPrintLeaves(BT);
    printf("\n求二叉树的高:\n");
    printf("%d", GetHeight(BT));
    return 0;
}