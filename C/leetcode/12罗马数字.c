#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int roman[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
const char* symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
char* intToRoman(int num) {
    char* ret = (char*)malloc(16*sizeof(char));
    char* tail = ret;
    for(int i = 0;i<13;i++)
    {
        while(num-roman[i]>0)
        {
            strcpy(tail,symbol[i]);
            tail = tail+strlen(symbol[i]); 
            num-=roman[i];
        }
    }
    return ret;
}
int main()
{
    printf("%s",intToRoman(3740));
    return 0;
}