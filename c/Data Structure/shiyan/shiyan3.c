#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
    输入样例：

1 4 5

1 3 6

输出样例：

1 1 3 4 5 6


*/
// 定义链表
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef node *linklist;

// 初始化链表
linklist initlinklist(linklist L)
{
    L = (linklist)malloc(sizeof(node));
    L->data = 0;
    L->next = NULL;
    return L;
}

// 添加节点
bool add(linklist L, int data)
{
    linklist tmp = (linklist)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = NULL;
    linklist pre = L;
    while (pre->next != NULL)
    {
        pre = pre->next;
    }
    pre->next = tmp;
    return true;
}

// 合并链表
linklist merge(linklist L1, linklist L2)
{
    linklist mergelist = initlinklist(mergelist);
    linklist p1 = L1, p2 = L2;
    p1 = p1->next;
    p2 = p2->next;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            add(mergelist, p1->data);
            p1 = p1->next;
        }
        else if (p1->data > p2->data)
        {
            add(mergelist, p2->data);
            p2 = p2->next;
        }
        else if (p1->data == p2->data)
        {
            add(mergelist, p1->data);
            p1 = p1->next;
            add(mergelist, p2->data);
            p2 = p2->next;
        }
    }
    while (!p1 || !p2)
    {
        if (p1 && !p2)
        {
            add(mergelist, p1->data);
            p1 = p1->next;
        }
        else if (!p1 && p2)
        {
            add(mergelist, p2->data);
            p2 = p2->next;
        }
        else if (!p1 && !p2)
        {
            break;
        }
    }
    return mergelist;
}

// 打印链表
void printL(linklist L)
{
    linklist tmp = L;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        printf("%d ", tmp->data);
    }
}

int main()
{
    linklist L1 = initlinklist(L1);
    linklist L2 = initlinklist(L2);
    int data;
    while (scanf("%d", &data) != EOF)
    {
        add(L1, data);
    }
    while (scanf("%d", &data) != EOF)
    {
        add(L2, data);
    }
    linklist L = merge(L1, L2);
    printL(L);
    return 0;
}