/*
8

A 1 2

B 3 4

C 5 -1

D -1 -1

E 6 -1

G 7 -1

F -1 -1

H -1 -1

8

G -1 4

B 7 6

F -1 -1

A 5 1

H -1 -1

C 0 -1

D -1 -1

E 2 -1

输出样例：True
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
// 定义树节点
typedef struct TreeNode
{
    char data;
    int left;
    int right;
} Tree;

Tree T1[MaxSize], T2[MaxSize];

// 构建树,返回树的根
int CreateTree(Tree T[])
{
    int n, root;
    scanf("%d", &n);
    if (n == 0)
        return -1;
    int check[n];
    for (int i = 0; i < n; i++)
        check[i] = 0;
    for (int i = 0; i < n; i++)
    {
        fflush(stdin); // 清除缓冲区
        scanf("%c %d %d", &T[i].data, &T[i].left, &T[i].right);
        if (T[i].left != -1)
            check[T[i].left] = 1;
        if (T[i].right != -1)
            check[T[i].right] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            root = i;
        }
    }
    return root;
}

// 判断是否同构
int isomorphism(int R1, int R2)
{
    if ((R1 == -1) && (R2 == -1))
    {
        return 1;
    }
    if (((R1 == -1) && (R2 != -1)) || ((R1 != -1) && (R2 == -1)))
    {
        return 0;
    }
    if (T1[R1].data != T2[R2].data)
    {
        return 0;
    }
    if ((T1[R1].left == -1) && (T2[R2].left == -1))
    {
        return isomorphism(T1[R1].right, T2[R2].right);
    }
    if (((T1[R1].left != -1) && (T2[R2].left != -1)) && ((T1[T1[R1].left].data) == (T2[T2[R2].left].data)))
    {
        return (isomorphism(T1[R1].left, T2[R2].left) && isomorphism(T1[R1].right, T2[R2].right));
    }
    else
    {
        return (isomorphism(T1[R1].left, T2[R2].right) && isomorphism(T1[R1].right, T2[R2].left));
    }
}
int main()
{
    int R1 = CreateTree(T1);
    int R2 = CreateTree(T2);
    if (isomorphism(R1, R2))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}