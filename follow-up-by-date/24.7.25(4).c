#include<stdio.h>
#include <string.h>
//µ¹ÖÃ×Ö·û´®²¢¾ÀÕıµ¥´ÊË³Ğò 
void reverse(char* left, char* right)
{
	while(left<right)
	{
		char temp='\0';
		temp=*left;
		*left=*right;
		*right=temp;
		left++,right--;
	}
}

int main(){
	char arr[101]={0};
	gets(arr);
	int count=0;
	int len=strlen(arr);
	reverse(arr,arr+len-1);
	char *start=arr;
	char *end=arr;
	while(*start)
	{
		while(*end!=' ' && *end !='\0')
		{
			end++;
		}
		reverse(start,end-1);
		if(*end!='\0')
			end++;
		start=end;
	}
	printf("%s",arr);
	
} 
