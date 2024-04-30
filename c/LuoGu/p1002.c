#include <stdio.h>
int majiao(int x,int y,int m,int n);
int main()
{
    int x,y,m,n;//x，y为终点坐标；m，n为马的坐标
    int cnt=0;//计数
    scanf("%d %d %d %d",&x,&y,&n,&m);
    int a[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            a[i][j]=0;
        }
        
    }
    
    for (int i = 0; i < x; i++)
    {
        a[i][0]=1;
        if(majiao(i,0,m,n))
        {
            break;
        }
    }
    for (int i = 0; i < y; i++)
    {
        a[0][i]=1;
        if (majiao(0,i,m,n))
        {
            break;
        }
    }
    for (int i = 1; i < x; i++)
    {
        for (int j = 1; j < y; j++)
        {
            if (majiao())
            {
                /* code */
            }
            
        }
        
    }
    
    
    
}
int majiao(int x,int y,int m,int n)//判断指定点是否在马脚上，输入指定点的坐标和马的坐标
{
    int flag=0;//标记值
    //马脚的所有坐标
    int b[9][2]={{m,n},{m+1,n+2},{m+2,n+1},{m+2,n-1},{m+1,n-2},{m-1,n-2},{m-2,n-1},{m-2,n+1},{m-1,n+2}};
    for(int i=0;i<9;i++)
    {
        if(x==b[i][0]&&y==b[i][1])
        {
            flag=1;
            break;
        }
    }
    return flag;
}