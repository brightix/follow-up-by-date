#include <stdio.h>

int main()
{   
    int input=0;
    int i,j;
    while(scanf(" %d",&input)==1)
    {   
        for(i=1;i<=input+1;i++)
        {   
            for(j=0;j<=input-i;j++)
            {
                printf("  ");
            }
            for(j=0;j<i;j++)
            {
                printf("*");
            }
            printf("\n");
        }
        for(i=input-1;i>=0;i--)//i=2-1
        {   
            for(j=0;j<input-i;j++)
            {
                printf("  ");
            }
            for(j=0;j<=i;j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}