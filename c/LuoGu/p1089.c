#include <stdio.h>
int main()
{
    int mum=0,sum=0,n;//mum为在妈妈那存的钱，sum为津津手中的钱
    for (int i = 1; i <= 12; i++)
    {
        sum+=300;
        scanf("%d",&n);
        if ((sum-n)<0)//判断现金是否够
        {
            printf("-%d",i);
            return 0;
        }else{
            sum-=n;
            if (sum>=100)
            {
                do{
                    sum-=100;
                    mum+=100;
                }while(sum>=100);
            }
        }
    }
    sum+=mum*1.2;
    printf("%d\n",sum);
    return 0;
    
}