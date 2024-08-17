#include <stdio.h>
#include <stdlib.h>
#define TRANSFORM_MAX 30

//空字符转为%20

char* transform(char* parr,int lenth)
{
    char* ret=(char*)malloc(lenth*sizeof(char));
    char* start=ret;
    int i=0;
    while(*parr)
    {
        if(*parr==' ')
        {
            *ret++ = '%';
            *ret++ = '2';
            *ret++ = '0';
            parr++;
            continue;
        }
        *ret++=*parr;
        i++;
        parr++;
    }
    *ret = '\0';
    return start;
}
int main()
{
    int lenth =50;
    char arr[TRANSFORM_MAX]="Happy New Year!";
    printf("arr =%s\n",arr);
    char* cons=transform(arr,lenth);
    printf("arr =%s\n",cons);
    free(cons);
    return 0;
}