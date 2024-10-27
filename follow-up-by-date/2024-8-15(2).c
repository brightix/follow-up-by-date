#include <stdio.h>

int strStr1(char* haystack, char* needle) {
    int i=0;
    int k=0;
    int temp=0;
    while(haystack[i]!='\0')//遍历haystack数组
    {   
        temp=i;
        while(haystack[i] == needle[k])//判断当前hay数组和needle首元素假如相同
        { 
            if(needle[k+1]=='\0')//假如遍历完所有needle数组后依然相等，返回下标
            {
                return temp;       
            }
            k++;//继续匹配第二项
            i++;
        } 
        k=0;
        i=temp+1;//若元素不相同            
    }
    return -1;
}

int strStr2(char* haystack, char* needle) {
    int i=0;
    char* p=strstr(haystack,needle);
    if(p==NULL)
        return -1;
    while((haystack+i)!=p)
    {
        i++;
    }
    return i;
}

int main()
{
    char arr1[10]="sfdbutsad";
    char arr2[10]="sad";
    int num = strStr(arr1,arr2);
    printf("%d",num);
    return 0;
}