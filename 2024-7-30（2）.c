#include <stdio.h>
#include <stdlib.h>

//��ϰqsort���� 
//�ѵõ�ʹ��while���� ��> 

int compare(const void* p1,const void * p2)
{
	return *(int*)p1 - *(int*)p2;
}

int main()
{
	int arr[10]={0};
	int i = 0;
	printf("����10����\n");
	while(i!=10)
	{
	scanf(" %d",&arr[i++]);	
	}
	while(getchar()!='\n');
	i = 0; 
	printf("����ǰ������\n");
	while(i!=10)
	{
	printf("%d ",arr[i++]);	
	}
	printf("\n");
	qsort(arr,10,sizeof(int),compare);
	printf("����������\n");
	i = 0; 
	while(i!=10)
	{
	printf("%d ",arr[i++]);	
	}
	return 0;
} 
