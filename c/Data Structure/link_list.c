#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 链表的定义
typedef int Elementtype;
typedef struct node
{
    Elementtype data;
    struct node *next;
} node;
typedef node *LinkList;

// 求链表的长度（默认有头节点）
int Length(LinkList L)
{
    LinkList p = L->next; // 临时指针用来遍历链表
    int cnt = 0;          // 计数器
    while (p)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}

// 查找
// 按序号查找 FindKth
Elementtype FindKth(LinkList L, int k) // k为序号
{
    LinkList p = L; // 临时指针
    int j = 0;
    while (p && j < k)
    {
        p = p->next;
        j++;
    }
    if (!p)
        printf("ERROR!");
    else
    {
        return p->data;
    }
}

// 按值查找，既定位Find
LinkList Find(LinkList L, Elementtype e)
{
    LinkList p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    if (!p)
        printf("ERROR!");
    else
        return p;
}

// 插入
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

// 删除
bool Delete(LinkList L, int i) // 表示要删除元素的位置
{
    LinkList pre = L, tmp;
    tmp = (LinkList)malloc(sizeof(node));
    int j = 0;
    while (pre && j < i - 1)
    {
        pre = pre->next;
        j++;
    }
    if (pre == NULL || j != i - 1 || pre->next == NULL)
    {
        return false;
    }
    else
    {
        tmp = pre->next;
        pre->next = tmp->next;
        free(tmp);
        return true;
    }
}

// 打印链表
void PrintList(LinkList L)
{
    LinkList p = L->next;
    if (!p)
    {
        printf("链表为空。\n");
    }
    else
    {
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    LinkList list = (LinkList)malloc(sizeof(node));
    list->next = NULL;
    Insert(list, 5, 1);
    Insert(list, 2, Length(list) + 1);
    Insert(list, 3, Length(list) + 1);
    Insert(list, 10, 2);
    PrintList(list);
    printf("%d\n", Length(list));
    printf("%d\n", FindKth(list, 2));
    Delete(list, 2);
    PrintList(list);
    LinkList a = Find(list, 2);
    printf("%d\n", a->data);
    printf("%d\n", a->next->data);
    return 0;
}