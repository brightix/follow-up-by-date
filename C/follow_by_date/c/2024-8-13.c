#include <stdio.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define PRINT(x) printf(#x" = %d\n",x)
#define SUM(x,y) printf("%d\n",x##y)
#define A 1
#define MY_OFFSETOF(TYPE,ELEMENT) (size_t)&(((TYPE*)0)->ELEMENT)
struct S
{
    char c1;//0
    int arr[5];//4
    int a1;//24
    char c2;//28
    //29
    //最大对齐数为4
    //sum=(29/4)*4
};
int main()
{
    int a = 5;
    int b = 10;
    PRINT(MAX(a,b));
    SUM(a, );
    //#undef SUM
#ifndef A
    printf("hehe\n");
#endif


    printf("%d\n",sizeof(struct S));
    printf("%d\n",((29+4/2)/4)*4);
    struct S s;
    printf("%d\n",MY_OFFSETOF(struct S,c1));
    printf("%d\n",MY_OFFSETOF(struct S,arr));
    printf("%d\n",MY_OFFSETOF(struct S,a1));
    printf("%d\n",MY_OFFSETOF(struct S,c2));
    return 0;
}