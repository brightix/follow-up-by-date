#include <stdio.h>

//input与其相邻的斐波那契的最小差

int Fib(int input)
{
    //int tmp=0;
    int a=2;
    int b=3;
    int c=3;
    if(input<0)
        return -1;
    if(input>=0 && input <=3) 
    {
        return 0;
    }
    while(input>c)
    {
        c=a+b;
        //tmp=a;
        a=b;
        b=c;
    }

    return c-input<input-a?c-input:input-a;
}

int main()
{
    int input=0;
    while(scanf("%d",&input)==1)
    {
        printf("%d\n",Fib(input));
    }
    return 0;
}