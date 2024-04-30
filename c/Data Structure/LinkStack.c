#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SNode
{
    int Data;
    struct SNode *Next;
} SNode;
typedef SNode *Stack;

// 创建堆栈
Stack CreateStack()
{
    Stack s = (Stack)malloc(sizeof(SNode));
    s->Next = NULL;
    return s;
}

// 判断是否为空
bool IsEmpty(Stack s)
{
    return (s->Next == NULL);
}

// 入栈
bool Push(Stack s, int x)
{
    SNode *tmp = (SNode *)malloc(sizeof(SNode));
    tmp->Data = x;
    tmp->Next = s->Next;
    s->Next = tmp;
    return true;
}

// 出栈
int Pop(Stack s)
{
    if (IsEmpty(s))
    {
        printf("栈空\n");
        return false;
    }
    else
    {
        SNode *tmp = (SNode *)malloc(sizeof(SNode));
        tmp = s->Next;
        int x = tmp->Data;
        s->Next = tmp->Next;
        free(tmp);
        return x;
    }
}

// 打印堆栈
bool PrintStack(Stack s)
{
    if (IsEmpty(s))
    {
        printf("栈空\n");
        return false;
    }
    else
    {
        SNode *tmp = s->Next;
        while (tmp)
        {
            printf("%d ", tmp->Data);
            tmp = tmp->Next;
        }
        return true;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Stack s = CreateStack();
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        Push(s, x);
    }
    PrintStack(s);
    return 0;
}
