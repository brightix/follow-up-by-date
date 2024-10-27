#include <stdio.h>
#include <assert.h>
//实现strstr函数

char* MyStrstr(const char* parr1, const char* parr2)
{
    char* ret;
    assert(parr1 && parr2);
    if (*parr2 == '\0') 
    {
        return (char*)parr1;
    }
    while(*parr1 != '\0')
    {
        int i=0;
        while(*(parr1+i) == *(parr2+i))
        {
            if(*(parr2+i+1) == '\0')
            {
                return (char*)parr1;              
            }
            i++;
        }
        parr1++;
    }
    return NULL;
}
int main()
{
    char arr1[]="hello world!";
    char arr2[]="wor";
    printf("%s",MyStrstr(arr1,arr2));
    return 0;
}