#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 顺序栈类型
typedef int ElementType;
typedef struct SNode
{
    ElementType *Data; // 存储元素的数组
    int top;           // 栈顶
    int MaxSize;       // 堆栈最大容量
} SNode;
typedef SNode *Stack;

// 生成空堆栈，其最大长度为MaxSize
Stack CreateStack(int MaxSize)
{
    Stack s = (Stack)malloc(sizeof(SNode));
    s->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    s->top = -1;
    s->MaxSize = MaxSize;
    return s;
}

// 判断堆栈s是否已满
bool IsFull(Stack s)
{
    return (s->top == s->MaxSize - 1);
}

// 判断堆栈s是否空
bool IsEmpty(Stack s)
{
    return (s->top == -1);
}

// 入栈
bool Push(Stack s, ElementType x)
{
    if (IsFull(s))
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
    if (IsEmpty(s))
    {
        printf("堆栈空\n");
    }
    else
    {
        return s->Data[(s->top)--];
    }
}

// 打印堆栈(从栈顶打印到栈底)
bool PrintStack(Stack s)
{
    if (IsEmpty(s))
    {
        printf("堆栈空\n");
        return false;
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d", s->Data[i]);
            if (i != 0)
                printf(" ");
        }
        printf("\n");
        return true;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Stack s = CreateStack(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        Push(s, x);
    }
    PrintStack(s);
    int a = Pop(s);
    PrintStack(s);
    printf("%d\n", a);
    return 0;
}
