#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DNode
{
    int data;
    struct DNode *next;
} DNode;
typedef DNode *Data;
typedef struct QNode
{
    Data front, rear;
    int Size;
} QNode;
typedef QNode *Queue;

Queue CreateQueue()
{
    Data d = (Data)malloc(sizeof(DNode));
    d->next = NULL;
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->front = Q->rear = d->next;
    Q->Size = 0;
    return Q;
}

bool IsEmpty(Queue Q)
{
    if (Q->Size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Insert(LinkList L, Elementtype e, int i) // i表示插入的位置
{
    LinkList pre = L; // pre作用是找到插入位置的前一个位置
    int j = 0;
    LinkList tmp = (LinkList)malloc(sizeof(node));
    tmp->data = e;
    while (pre && j < i - 1)
    {
        pre = pre->next;
        j++;
    }
    if (pre == NULL || j != i - 1)
    {
        free(tmp);
        return false;
    }
    else
    {
        tmp->next = pre->next;
        pre->next = tmp;
        return true;
    }
}

bool AddQ(Queue Q, int x)
{
    Insert(d, )
}
