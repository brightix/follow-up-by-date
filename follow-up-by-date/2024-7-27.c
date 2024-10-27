#include <stdio.h>

//实现strcpy函数功能 

char* my_strcpy(char* arr,const char* arr2)
{
	int i=0;
	while(arr2[i]!='\0')
	{
		arr[i]=arr2[i++];
	}
	arr[i]='\0';
	return arr;
}
int main(){
	char arr[20]="I love you";
	char arr2[20]={0};
	printf("arr = %s\n",arr);
	printf("input string\n");
	printf("arr = %s",my_strcpy(arr,gets(arr2)));
}
