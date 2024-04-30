#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define maxsize 100

typedef struct
{
    double *data;
    int top;
} DataStack;

typedef struct
{
    char *operators;
    int top;
} OperatorStack;

DataStack *createDataStack()
{
    DataStack *stack = (DataStack *)malloc(sizeof(DataStack));
    stack->data = (double *)malloc(sizeof(double) * maxsize);
    stack->top = -1;
    return stack;
}

OperatorStack *createOperatorStack()
{
    OperatorStack *stack = (OperatorStack *)malloc(sizeof(OperatorStack));
    stack->operators = (char *)malloc(sizeof(char) * maxsize);
    stack->top = -1;
    return stack;
}

void pushData(DataStack *stack, double value)
{
    if (stack->top < maxsize - 1)
    {
        stack->data[++stack->top] = value;
    }
}

void pushOperator(OperatorStack *stack, char operator)
{
    if (stack->top < maxsize - 1)
    {
        stack->operators[++stack->top] = operator;
    }
}

double popData(DataStack *stack)
{
    if (stack->top != -1)
    {
        return stack->data[stack->top--];
    }
    return 0; // Should handle underflow properly
}

char popOperator(OperatorStack *stack)
{
    if (stack->top != -1)
    {
        return stack->operators[stack->top--];
    }
    return 0; // Should handle underflow properly
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

void evaluate(OperatorStack *ops, DataStack *values)
{
    if (ops->top == -1 || values->top < 1)
        return;
    char op = popOperator(ops);
    double b = popData(values);
    double a = popData(values);
    pushData(values, applyOp(a, b, op));
}

int main()
{
    char expression[] = "20*(4.5-3)";
    DataStack *values = createDataStack();
    OperatorStack *ops = createOperatorStack();

    for (int i = 0; expression[i] != '\0';)
    {
        if (expression[i] == ' ')
        {
            i++;
            continue;
        }

        if (isdigit(expression[i]))
        {
            double val = 0;
            while (i < strlen(expression) && (isdigit(expression[i]) || expression[i] == '.'))
            {
                if (expression[i] == '.')
                {
                    double decimal = 0.1;
                    i++;
                    while (i < strlen(expression) && isdigit(expression[i]))
                    {
                        val += (expression[i] - '0') * decimal;
                        decimal *= 0.1;
                        i++;
                    }
                }
                else
                {
                    val = (val * 10) + (expression[i] - '0');
                    i++;
                }
            }
            pushData(values, val);
        }

        if (i < strlen(expression) && isOperator(expression[i]))
        {
            if (expression[i] == '(')
            {
                pushOperator(ops, expression[i]);
            }
            else if (expression[i] == ')')
            {
                while (ops->top != -1 && ops->operators[ops->top] != '(')
                {
                    evaluate(ops, values);
                }
                popOperator(ops); // pop '('
            }
            else
            {
                while (ops->top != -1 && precedence(ops->operators[ops->top]) >= precedence(expression[i]))
                {
                    evaluate(ops, values);
                }
                pushOperator(ops, expression[i]);
            }
            i++;
        }
    }

    while (ops->top != -1)
    {
        evaluate(ops, values);
    }

    printf("%.2f\n", popData(values));

    // Free allocated memory
    free(values->data);
    free(values);
    free(ops->operators);
    free(ops);

    return 0;
}
