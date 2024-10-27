#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main()
{   
    /*
    int a=0;
    int* p=NULL;
    p=&a;
    p=NULL;
    assert(p);
    printf("%p",p);
    */
    char arr[10]="hello";
    char* p = (char*)malloc(40);
    strcpy(p,arr);
    printf("%s\n",p);
    printf("%p\n",p);
    free(p);
    printf("%s\n",arr);
    printf("%s\n",p);
    printf("%p\n",p);
    p=NULL;
    int n=100;
    int* pc=malloc(n);
    char* str="hello";
    printf(str); 
    return 0;
}