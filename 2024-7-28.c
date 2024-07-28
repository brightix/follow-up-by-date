#include <stdio.h>
#include <string.h> 
//3110. ×Ö·û´®µÄ·ÖÊý
int scoreOfString(char* s) {
    unsigned int sum=0;
    int sz=strlen(s),i;
    int sum_=0;
    if(sz==1)
        return s[0];
    for(i=0;i<sz;i++)
    {
    	if((s[i]-s[i+1])<0)sum-=s[i]-s[i+1];

		else sum+=s[i]-s[i+1];

        if(s[i+2]=='\0')
            break;
    }
    return sum;
}
