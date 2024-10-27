#include <stdio.h>
#include <string.h>
#include <assert.h>

//实现strcpy函数的功能

void my_strcpy(char* destination,const char* source)
{
    assert(destination);
    assert(source);
    while(*destination++ = *source++);
    *destination='\0';
}
int main()
{
    char arr1[7]="abcdef";
    char arr2[7]={'g','o','o','d','\0'};
    printf("arr1 = %s,arr2 = %s\n",arr1,arr2);
    my_strcpy(arr2,arr1);
    printf("arr1 = %s,arr2 = %s\n",arr1,arr2);
    return 0;
}