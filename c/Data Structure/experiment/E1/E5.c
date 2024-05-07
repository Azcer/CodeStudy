#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*输入样例：

10

    9 4 6 1 8 3 7 0 2 5

    输出样例：

    0 1 2 3 4 5 6 7 8 9
*/

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

int GetMaxDigit(int *num, int len) // 获取数组中的最高位数
{
    int k = 0, cnt = 0, con = 0;
    for (int i = 0; i < len; i++)
    {
        con = num[i];
        while (num[i] > 0)
        {
            num[i] /= 10;
            cnt++;
        }
        if (cnt > k)
            k = cnt;
        cnt = 0;
        num[i] = con;
    }
    return k;
}

int GetKey(int num, int digit) // 获取某位的值
{
    int key = 0;
    while (digit > 0)
    {
        key = num % 10;
        num /= 10;
        digit--;
    }
    return key;
}

void RadixSort(int *num, int len)
{
    Queue QueueArray[10];
    for (int i = 0; i < 10; i++)
    {
        QueueArray[i] = CreateQueue(100);
    }
    for (int i = 0; i < GetMaxDigit(num, len); i++)
    {
        for (int j = 0; j < len; j++)
        {
            switch (GetKey(num[j], i + 1))
            {
            case 0:
                AddQ(QueueArray[0], num[j]);
                break;
            case 1:
                AddQ(QueueArray[1], num[j]);
                break;
            case 2:
                AddQ(QueueArray[2], num[j]);
                break;
            case 3:
                AddQ(QueueArray[3], num[j]);
                break;
            case 4:
                AddQ(QueueArray[4], num[j]);
                break;
            case 5:
                AddQ(QueueArray[5], num[j]);
                break;
            case 6:
                AddQ(QueueArray[6], num[j]);
                break;
            case 7:
                AddQ(QueueArray[7], num[j]);
                break;
            case 8:
                AddQ(QueueArray[8], num[j]);
                break;
            case 9:
                AddQ(QueueArray[9], num[j]);
                break;
            default:
                break;
            }
        }
        int index = 0, l = 0;
        while (index < len)
        {
            while (l < 10)
            {
                if (IsEmpty(QueueArray[l]))
                {
                    l++;
                }
                else
                {
                    while (!IsEmpty(QueueArray[l]))
                    {
                        num[index++] = DeleteQ(QueueArray[l]);
                    }
                    l++;
                }
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    RadixSort(num, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}