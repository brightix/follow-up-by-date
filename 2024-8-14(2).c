#include <stdio.h>
int main()
{
    int score=0;
    int min =100;
    int max=0;
    int n=0;
    float sum=0.0;
    while(scanf(" %d",&score)==1)
    {
        n++;
        if(score<min)
            min=score;
        if(score>max)
            max = score;
        sum+=score;
        if(n==7)
        {
            printf("%.2f\n",sum-=max+min/5.0);
            min =100;
            max=0;
            n=0;
            sum=0.0;
        }
    }
    return 0;
}