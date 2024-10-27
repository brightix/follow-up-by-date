#include <stdio.h>
#include <string.h>

char* MyStrtok(char* dest,const char* sep)
{
    char* (*ret)[]={0};
    while(*dest != '\0')
    {
        char*  = dest;
        if(*dest == *sep)
        {
            
        }
    }
}

int main()
{
    const char* sep="@.";
    char email[]="2181127875@qq.com";
    char cp[30]={0};
    strcpy(cp,email);
    MyStrtok(cp,sep);
}