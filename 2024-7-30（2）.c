#include <stdio.h>
#include <stdlib.h>

//练习qsort函数 
//难得的使用while遍历 ：> 

int compare(const void* p1,const void * p2)
{
	return *(int*)p1 - *(int*)p2;
}

int main()
{
	int arr[10]={0};
	int i = 0;
	printf("输入10个数\n");
	while(i!=10)
	{
	scanf(" %d",&arr[i++]);	
	}
	while(getchar()!='\n');
	i = 0; 
	printf("排序前的数组\n");
	while(i!=10)
	{
	printf("%d ",arr[i++]);	
	}
	printf("\n");
	qsort(arr,10,sizeof(int),compare);
	printf("排序后的数组\n");
	i = 0; 
	while(i!=10)
	{
	printf("%d ",arr[i++]);	
	}
	return 0;
} 
