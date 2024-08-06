#include <stdio.h>
int main()
{
    int input=0;
    int i,j;
    int arr[10][10]={0};
    printf("please input the number by which the triangle is needed to be created\n");
    scanf("%d",&input);
    for(i=0;i<10;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0 || j==i)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    for(i=0;i<input;i++)
    {
        for(int k=0;k<input-i-1;k++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {

            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}