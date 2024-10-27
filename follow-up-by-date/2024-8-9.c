#include <stdio.h>
#include <stdlib.h>

//水一天，今天学的都是理论的内存函数

union house
{
    char a;
    int b;
    char c;

};

int main()
{
    /*    union house room;
    room.a='t';
    printf("%x\n",room.a);
    room.b=0x11223344;
    printf("%x\n",room.b);
    room.c=0x43;
    printf("%x\n",(int)room.c);
    printf("%x\n",(int)room.b);
    //printf("%d\n",room.b);
    int* pa=(int*)malloc(4*(sizeof(typeof(*pa))));
    int j=0;
    for(int i=0;i<4;i++)
    {

        *(pa+i)=1+j++;
    }

    for(int i=0;i<4;i++)
    {
        printf("%d\n",*(pa+i));
    }
    free(pa);
    printf("----------\n");
    pa=NULL;
    for(int i=0;i<4;i++)
    {
        printf("%p\n",pa+i);
    }
    int i=0;
    int *p=0x000000000012f40;//尝试实践出系统安全指针范围但是失败了
    while(1)
    {
        printf("%p\n",p+i);   
        printf("%d\n",*(p+i)); 
        printf("this %d times\n",i++);
    }
*/
    int* pa=NULL;
    int*ptr=(int*)calloc(10,sizeof(typeof(*pa)));
    return 0;
}