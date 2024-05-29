#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 哈夫曼树节点结构体
typedef struct
{
    int weight; // 字符权重
    int parent; // 父节点索引
    int left;   // 左子节点索引
    int right;  // 右子节点索引
} HuffmanNode;

// 交换两个节点的位置
void swap(HuffmanNode *a, HuffmanNode *b)
{
    HuffmanNode temp = *a;
    *a = *b;
    *b = temp;
}

// 按照权重对节点进行排序
void sortNodes(HuffmanNode nodes[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (nodes[j].weight > nodes[j + 1].weight)
            {
                swap(&nodes[j], &nodes[j + 1]);
            }
        }
    }
}

// 创建哈夫曼树
void createHuffmanTree(HuffmanNode nodes[], int size)
{
    sortNodes(nodes, size);

    for (int i = 0; i < size - 1; i++)
    {
        nodes[i].parent = -1;
    }

    int index = 0;
    while (size > 1)
    {
        int min1 = -1, min2 = -1;
        for (int i = 0; i < size; i++)
        {
            if (nodes[i].parent == -1)
            {
                if (min1 == -1)
                {
                    min1 = i;
                }
                else if (nodes[i].weight < nodes[min1].weight)
                {
                    min2 = min1;
                    min1 = i;
                }
                else if (nodes[i].weight < nodes[min2].weight)
                {
                    min2 = i;
                }
            }
        }

        nodes[min1].parent = index;
        nodes[min2].parent = index;

        nodes[index].weight = nodes[min1].weight + nodes[min2].weight;
        nodes[index].left = min1;
        nodes[index].right = min2;

        size--;
        index++;
    }
}

// 打印哈夫曼编码
void printHuffmanCodes(HuffmanNode nodes[], int size)
{
    char codes[10][10];
    for (int i = 0; i < size; i++)
    {
        int parent = nodes[i].parent;
        if (parent == -1)
        {
            strcpy(codes[i], "0");
        }
        else
        {
            strcpy(codes[i], "");
            while (parent != -1)
            {
                if (nodes[parent].left == i)
                {
                    strcat(codes[i], "0");
                }
                else
                {
                    strcat(codes[i], "1");
                }
                parent = nodes[parent].parent;
            }
        }
        printf("%c: %s\n", i, codes[i]);
    }
}

int main()
{
    char str[100];
    printf("请输入字符串：");
    scanf("%s", str);

    HuffmanNode nodes[256];
    for (int i = 0; i < strlen(str); i++)
    {
        nodes[str[i]].weight++;
    }

    int size = 0;
    for (int i = 0; i < 256; i++)
    {
        if (nodes[i].weight > 0)
        {
            size++;
        }
    }

    createHuffmanTree(nodes, size);
    printHuffmanCodes(nodes, size);

    return 0;
}