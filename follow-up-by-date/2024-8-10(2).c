#include <stdio.h>

/*
long long sum(long long x,long long y)
{
    long long i,j;
    long long LCM = 0;
    long long GCD = 0;
    long long MAX = x>y?x:y;//找出较大值
    long long MIN = x<y?x:y;//找出较小值
    
    for(i=MAX;i<=(long long)(x*y);i+=MAX)//找最小公倍数LCM
    {
        if(i%MIN==0)
        {
            LCM=i;
            break;            
        }

    }
    for(j=MIN;j>=1;j--)//找最大公因数GCD
    {
        if(x%j==0 && y%j==0)
        {
            GCD=j;
            break;      
        }

    }
    printf("最小公倍数 =  %lld,最大公因数 = %lld\n",LCM,GCD);
    return LCM+GCD;
}
int main()
{
    long long x = 0, y = 0;
    while (1)
    {
        printf("please enter two numbers:>");
        if (scanf("%d %d", &x, &y) != 2) 
        {
            printf("invalid\n");
            while(getchar() != '\n');
            continue;
        }
        printf("sum = %lld\n", sum(x, y));    
    }
    return 0;
}
*/



long long GCD(long x,long y)
{
    long long max=x>y?x:y;
    long long min=x<y?x:y;
    if((max%min)!=0)
    {
        min=GCD(min,max%min);
    }

    return min;
}

long long LCM(long long x,long long y,long long gcd)
{
    return (x*y)/gcd;
}
char main()//改进过后的最大公因数最小公倍数和的算法
{
    long long a=0,b=0;
    while((scanf("%lld %lld",&a,&b))!=EOF)
    {
        long long gcd = GCD(a,b);
        long long lcm = LCM(a,b,gcd);
        printf("%lld",gcd+lcm);
    }
    return 'c';
}
