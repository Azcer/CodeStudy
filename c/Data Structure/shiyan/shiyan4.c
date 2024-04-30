#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define maxsize 100
/*
输入样例：

20*(4.5-3)

输出结果：

30.00
*/

// 定义栈
typedef struct DataNode
{
    double *Data;
    int top;
    int size;
} DataNode;
typedef DataNode *DataStack; // 数据栈
typedef struct OperatorNode
{
    char *Operator;
    int top;
    int size;
} OperatorNode; // 操作栈
typedef OperatorNode *OperatorStack;

// 创建一个空栈
DataStack CreateDataStack(int size) // 创建一个空的数据栈
{
    DataStack DS = (DataStack)malloc(sizeof(DataNode));
    DS->Data = (double *)malloc(sizeof(double) * size);
    DS->top = -1;
    DS->size = size;
    return DS;
}
OperatorStack CreateOperatorStack(int size) // 创建一个空的操作栈
{
    OperatorStack OS = (OperatorStack)malloc(sizeof(OperatorNode));
    OS->Operator = (char *)malloc(sizeof(char) * size);
    OS->top = -1;
    OS->size = size;
    return OS;
}

// 判断栈满
bool IsFullDS(DataStack DS) // 判断数据栈
{
    return DS->top == (DS->size - 1);
}
bool IsFullOS(OperatorStack OS) // 判断操作栈
{
    return OS->top == (OS->size - 1);
}

// 入栈
bool PushDS(DataStack DS, double x)
{ // 数据入栈
    if (IsFullDS(DS))
    {
        printf("栈已满！");
        return false;
    }
    else
    {
        DS->Data[++(DS->top)] = x;
        return true;
    }
}

bool PushOS(OperatorStack OS, char x) // 操作入栈
{
    if (IsFullOS(OS))
    {
        printf("栈已满！");
        return false;
    }
    else
    {
        OS->Operator[++(OS->top)] = x;
        return true;
    }
}

// 判断栈空
bool IsEmptyDS(DataStack DS)
{
    return DS->top == -1;
}
bool IsEmptyOS(OperatorStack OS)
{
    return OS->top == -1;
}

// 出栈
double PopDS(DataStack DS)
{
    if (IsEmptyDS(DS))
    {
        printf("栈已空！");
        return false;
    }
    else
    {
        return DS->Data[(DS->top)--];
    }
}
char PopOS(OperatorStack OS)
{
    if (IsEmptyOS(OS))
    {
        printf("栈已空！");
        return '0';
    }
    else
    {
        return OS->Operator[(OS->top)--];
    }
}

const char opers[6] = {'+', '-', '*', '/', '(', ')'};
bool judge(char x) // 判断是否是运算符
{
    for (int i = 0; i < 6; i++)
    {
        if (x == opers[i])
            return true;
    }
    return false;
}

int priority(char x) // 运算符的优先级
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

double calculate(double x1, double x2, char oper)
{
    if (oper == '+')
        return (x1 + x2);
    else if (oper == '-')
        return (x1 - x2);
    else if (oper == '*')
        return (x1 * x2);
    else if (oper == '/')
        return (x1 / x2);
}

int main()
{
    DataStack DS = CreateDataStack(maxsize);
    OperatorStack OS = CreateOperatorStack(maxsize);
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    double num = 0, decimal = 0.1;
    int index = 0; // 索引
    while (index < len)
    {
        while (!judge(s[index]) && s[index] != '.' && index < len) // 整数部分
        {
            num = num * 10 + (s[index] - '0');
            index++;
            if (index == len)
                PushDS(DS, num);
        }
        if (s[index] == '.') // 小数部分
        {
            index++;
            while (!judge(s[index]) && index < len)
            {
                num = num + (s[index] - '0') * decimal;
                decimal *= 0.1;
                index++; // 将 index 的增加放在循环内部处理
            }
        }
        if (judge(s[index]))
        {
            if (!judge(s[index - 1]))
            {
                PushDS(DS, num);
                num = 0; // 清零，为下一个整数或小数部分做准备
                decimal = 0.1;
            }
            if (OS->top == -1) // 判断是否是第一个操作符
            {
                PushOS(OS, s[index]);
                index++;
            }
            else if (s[index] == '(')
            {
                PushOS(OS, s[index++]);
            }

            else if (s[index] == ')') // 操作符为')'时
            {
                char oper = PopOS(OS);
                while (oper != '(')
                {
                    double x2 = PopDS(DS);
                    double x1 = PopDS(DS);
                    PushDS(DS, calculate(x1, x2, oper));
                    oper = PopOS(OS);
                }
                index++;
            }
            else
            {
                if (priority(s[index]) > priority(OS->Operator[OS->top])) // 扫描到的操作符的优先级大于栈顶的优先级
                {
                    PushOS(OS, s[index]);
                    index++;
                }
                else
                {
                    char oper = PopOS(OS);
                    double x2 = PopDS(DS);
                    double x1 = PopDS(DS);
                    PushDS(DS, calculate(x1, x2, oper));
                    PushOS(OS, s[index]);
                    index++;
                }
            }
        }
    }
    while (!IsEmptyOS(OS))
    {
        char oper = PopOS(OS);
        double x2 = PopDS(DS);
        double x1 = PopDS(DS);
        PushDS(DS, calculate(x1, x2, oper));
    }
    printf("%.2lf\n", PopDS(DS));
    return 0;
}
