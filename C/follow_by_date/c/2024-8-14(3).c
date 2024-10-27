#include <stdio.h>
#include <ctype.h>
#include <math.h>

//实现atof函数功能，半自主

double my_atof(const char* p)
{
    int sign=1;
    int exponentSign=1;
    int exponent=0;
    double result=0.0;
    double fraction=1.0;
    while(*p==' ' || *p=='\t')
    {
        p++;
    }
    if(*p=='-')
    {
        sign=-1;     
        p++;
    }
    else if(*p=='+')
        p++;
    while(isdigit(*p))
    {
        result=result*10.0+(*p-'0');
        p++;
    }
    if(*p=='.')
    {
        p++;
        while(isdigit(*p))
        {
            fraction*=0.1;
            result+=fraction*(*p-'0');
            p++;
        }
    }
    if(*p=='e' || *p=='E')
    {
        p++;
        if(*p=='-')
        {
            exponentSign=-1;
            p++;            
        }
        else if (*p=='+')
        {
            p++;
        }
        while(isdigit(*p))
        {
            exponent=exponent*10+(*p - '0');
            p++;
        }
        result*=pow(10,exponent*exponentSign);
    }
    return result*sign;
}

int main()
{
    char arr[20]="-321.2314e-7";
    printf("%g",my_atof(arr));
    return 0;
}