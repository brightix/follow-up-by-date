#include <stdio.h>
#include <stdlib.h>
//��ѧmalloc�������˽�malloc��free��������ԭ�� 


void creatAndPrintArray(int n)
{
	int* arr=(int*)malloc(n * sizeof(int));
	if(arr == NULL)
	{
		printf("initialize fialed\n");
		return;		
	}

	int i;
	for(i=0;i<n;i++)
	{
		arr[i]=i+1;
		printf("%d ",arr[i]);
	}	
	free(arr);
}

int main()
{
	int n=0;
	while(1)
	{
		printf("�������\n");
		scanf(" %d",&n);
		creatAndPrintArray(n);
	}
	return 0;
}
