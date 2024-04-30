#include <stdio.h>
int main()
{
    int l,m;
    scanf("%d %d",&l,&m);
    //初始化道路
    int a[l+1];
    for (int i = 0; i <= l; i++)
    {
        a[i]=1;
    }
    //存入地铁数据
    int b[m][2];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    //处理树
    for (int i = 0; i < m; i++)
    {
        for (int j = b[i][0]; j <= b[i][1]; j++)
        {
            a[j]=0;
        }
    }
    //计数
    int cnt=0;
    for (int i = 0; i <= l; i++)
    {
        if (a[i]==1)
        {
            cnt++;
        }
        
    }
    printf("%d\n",cnt);
    
    return 0;
}