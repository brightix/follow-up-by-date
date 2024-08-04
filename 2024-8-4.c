#include <stdio.h>
#include <assert.h>

int IsStrEqual(const char* parr,const char* parr2)
{
    assert(parr && parr2);
    while(*parr==*parr2)
    {
        if(*parr=='\0')
            return 1;
        parr++,parr2++;
    }
    return -1;
}

int MyStrcmp(const char* parr,const char* parr2)
{
    assert(parr && parr2);
    while(*parr == *parr2)
    {
        if(*parr == '\0')
            return 0;
        parr++,parr2++;
    }
    return *parr - *parr2;
}

int main()
{
    char arr1[]="1234";
    char arr2[]="1234";
    char arr3[]={'1','2','3','4','5','\0'};
    printf("%d\n",IsStrEqual(arr1,arr2));
    printf("%d\n",IsStrEqual(arr2,arr3));
    printf("%d\n",MyStrcmp(arr1,arr2));
    printf("%d\n",MyStrcmp(arr2,arr3));
    return 0;
}