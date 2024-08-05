#include <stdio.h>
#include <string.h>
#include <assert.h>

//模拟实现memcpy函数
void* my_memcpy(void* dest,void* sour,size_t num)
{
    assert(dest && sour);
    void* ret=dest;
    if(dest>sour)
    {
        while(num--)
        *((char*)dest+num)=*((char*)sour+num);
    }
    else
    {
        while(num--)
        {
            *((char*)dest)=*((char*)sour);
            dest++,sour++;
        }        
    }
    return ret;
}


/*
int main()
{
    int arr1[10]={1,2,3,4,5,6,7,8,9,10};
    int arr2[]={4,5,6,7,8};
    int sz = sizeof(arr2)/sizeof(arr2[0]);
    printf("before arr1 = ");
    for(int i = 0;i<10;i++)
    {
        printf("%d",arr1[i]);
    }
    memcpy(arr1,arr2,sz*sizeof(typeof(arr2[0])));
    printf("\nafter arr1 = ");
    for(int i = 0;i<10;i++)
    {
        printf("%d",arr1[i]);
    }
    printf("\n%d",sizeof(typeof(arr2[0])));
    return 0;
}*/

int main()
{
    int arr1[10]={1,2,3,4,5,6,7,8,9,10};
    int arr2[]={4,5,6,7,8};
    int sz = sizeof(arr2)/sizeof(arr2[0]);
    printf("before arr1 = ");
    for(int i = 0;i<10;i++)
    {
        printf("%d",arr1[i]);
    }
    my_memcpy(arr1,arr1+2 ,5*sizeof(typeof(arr2[0])));
    printf("\nafter arr1 = ");
    for(int i = 0;i<10;i++)
    {
        printf("%d",arr1[i]);
    }
    printf("\n%d",sizeof(typeof(arr2[0])));
    return 0;
}