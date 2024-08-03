#include <stdio.h>
#include <assert.h>

//实现strcat函数的功能

char* MyStrcat(char* dest,const char* source)
{
    assert(dest && source);
    char* ret = dest;
    while(*dest !='\0')
    dest++;
    while(*dest++ = *source++);
    return ret;

}

int main()
{
    char arr[20]={'h','e','l','l','o','\0'}
    ;
    char arr2[8]=" world!";
    printf("befor arr = %s\n",arr);
    MyStrcat(arr,arr);
    printf("after arr = %s",arr);
    return 0;
}