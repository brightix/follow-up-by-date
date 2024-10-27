#include <stdio.h>

//水一期指针运算

int main()
{
    /*char arr[]={1,2,3};
    printf("%p\n",&arr);
    printf("%p\n",&arr[0]);
    printf("%p\n",&arr[0]+1);
    printf("%p\n",&arr[1]);
    return 0;
    char arr[6]="abcdef";
    char* p = &arr;
    printf("%p\n",*p);
    printf("%p\n",*p+1);
    printf("%p\n",p);
    printf("%p\n",p+1);
    return 0;
    
   int a=0,b=2;
    printf("%d\n",&a);
    printf("%d\n",a);
    printf("%p\n",&a);
    printf("%p\n",a);
    printf("%d\n",sizeof(long long int ));
    printf("%d\n",sizeof(long int ));
    printf("%d\a",sizeof(int));
    return 0;
    */
   int a[5][5];
   int(*p)[4];
   p=(int(*)[4])a;
   printf("%p\n",p);
   printf("%p\n",p+1);
   return 0;
}