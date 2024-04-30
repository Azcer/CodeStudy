#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
    输入样例：

3   4

-5  2

6   1

-2  0

输出样例：

12  3

-10  1

6   0
*/
// 定义多项式
typedef struct node
{
    int coefficient; // 系数
    int index;       // 指数
    struct node *next;
} node;
typedef node *polynomial;
polynomial initpolynomial() // 初始化多项式
{
    polynomial p = (polynomial)malloc(sizeof(node));
    p->coefficient = 0;
    p->index = 0;
    p->next = NULL;
    return p;
}
bool add(polynomial p, int coefficient, int index) // 添加项
{
    polynomial tmp = (polynomial)malloc(sizeof(node));
    tmp->coefficient = coefficient;
    tmp->index = index;
    tmp->next = NULL;
    polynomial pre = p;
    while (pre->next != NULL)
    {
        pre = pre->next;
    }
    pre->next = tmp;
    return true;
}
polynomial Derive(polynomial p) // 求导
{
    polynomial tmp = p, q = p;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        tmp->coefficient = tmp->coefficient * tmp->index;
        tmp->index--;
    }
    return p;
}
void printp(polynomial p) // 打印多项式
{
    polynomial tmp = p;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->index != -1)
            printf("%d %d\n", tmp->coefficient, tmp->index);
    }
}

int main()
{
    int coefficient, index;
    polynomial p = initpolynomial(p);
    while (scanf("%d %d", &coefficient, &index) != EOF)
    {
        add(p, coefficient, index);
    }
    p = Derive(p);
    printp(p);
    return 0;
}
