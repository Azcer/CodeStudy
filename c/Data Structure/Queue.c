#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QNode
{
    int *data;
    int front, rear; /*头指针和尾指针*/
    int MaxSize;     /*队列最大容量*/
} QNode;
typedef QNode *Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->data = (int *)malloc(sizeof(int) * MaxSize);
    Q->front = Q->rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->rear + 1) % Q->MaxSize == Q->front);
}

bool AddQ(Queue Q, int x)
{
    if (IsFull(Q))
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

bool IsEmpty(Queue Q)
{
    return (Q->front == Q->rear);
}

int DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("队列空！\n");
        return false;
    }
    else
    {
        Q->front = (Q->front + 1) % Q->MaxSize;
        return Q->data[Q->front];
    }
}
int main()
{
    Queue Q = CreateQueue(3);
    AddQ(Q, 3);
    printf("%d", DeleteQ(Q));
    return 0;
}