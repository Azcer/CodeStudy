#include <stdio.h>
int main()
{
    int L,R,cnt=0;
    scanf("%d %d",&L,&R);
    for (int i = L; i <= R; i++)//遍历所有数
    {
        int t=i;
        while(t>0)
        {
           if(t%10==2)
           cnt++;
           t/=10;
        
        }
    }
    printf("%d\n",cnt);
    return 0;
}