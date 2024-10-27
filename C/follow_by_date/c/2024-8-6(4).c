#include <stdio.h>
//矩阵转换

void userInput(char(*parr)[10],int* r,int *c)
{
    int i,j;
    printf("enter the row and the col:>");
    scanf(" %d %d",r,c);
    while(getchar()!='\n');
    for(i=0;i<*r;i++)
    {
        printf("enter the elements of the %d row:>",i+1);
        for(j=0;j<*c;j++)
        {
            scanf(" %c",&parr[i][j]);
        }
        while(getchar()!='\n');
    }
}

void displayArr(char(*parr)[10],int r,int c)
{   
    int i,j;
    int biggest = r>c?r:c;
    for(i=0;i<biggest;i++)
    {
        for(j=0;j<biggest;j++)
        {
            printf("%c ",parr[i][j]);
        }
        printf("\n");
    }
}

void reverse(char(*parr)[10],int r,int c)
{
    int i,j;
    int temp;
    int biggest = r>c?r:c;
    for(i=0;i<biggest;i++)
    {

        for(j=0;j<i;j++)
        {        
            temp=parr[i][j];
            parr[i][j]=parr[j][i];
            parr[j][i]=temp;
        }
    }
}

int main()
{
    char arr[10][10]={0};//{'1','2','3'},{'4','5','6'}
    int r=0;
    int c=0;
    int i,j;
    userInput(arr,&r,&c);
    displayArr(arr,r,c);
    reverse(arr,r,c);
    displayArr(arr,r,c);
    return 0;
}