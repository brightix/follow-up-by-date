#include <ctype.h>

//58.最后一个单词的长度 简单

int lengthOfLastWord(char* s) {
    int count=0;
    char* ps=s;
    while(*s != '\0')
    {
        s++;
    }
    s--;
    while(isspace(*s))
        s--;
    while(isalpha(*s))
    {
        count++;
        if(s==ps)
            break;
        s--;
        
    }
    return count;
}