#include<stdio.h>

int main(){
	int a=0,b=0;
	int i=1;
	while(scanf("%d%d",&a,&b))
	{
		/*
		for(i=a>b?a:b;i<100000;i++)//����һ 
		{
			if(i%a==0 && i%b==0)
			{
				printf("��С������Ϊ%d\n",i);
				break;		
			}
		}*/	
		
		
		while((i*a)%b!=0)//������  �ٶȸ��� 
		{
			i++;
		}
		printf("��С������Ϊ%d\n",i*a);
		while(getchar()!='\n');//��ջ����� 
	}
	return 0;
}
