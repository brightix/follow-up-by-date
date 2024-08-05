#include <stdio.h>
#include <errno.h>
#include <string.h>
//fopen初体验
int main()
{
    FILE* pf=fopen("C:\\Users\\21811\\Desktop\\test.txt","r");
    if(pf == NULL)
    {   
        printf("%s\n",strerror(errno));
        return 1;
    }
    printf("hello\n");
    return 0;
}