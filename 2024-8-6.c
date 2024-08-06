#include <stdio.h>
//打印‘*’并且附带空格
int main()
{
    int input=0,i,j;
    while(scanf("%d",&input)==1)
    {
        for(i=0;i<input;i++)
        {
            for(j=0;j<=input;j++)
            {
                if(i+j>=input)
                    printf("%c ",'*');
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}