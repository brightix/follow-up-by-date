#include <stdio.h>


void isTriangle(const int a,const int b, const int c)
{
	if(a!=0 && b!=0 && c!=0)//�жϱ߳��Ϸ��� 
	{
		if(a<b+c && b<a+c && c<a+b)//��������������֮��һ�����ڵ�����
		{
			if(a==b||b==c||a==c)//�ж����������� 
			{
				if(a==b && a==c)
					printf("�����������ɵ����������Ա߳�Ϊ%d�ĵȱ������Ρ�\n",a); 
				else if(a==b)
					printf("�����������ɵ���������������Ϊ%d�ĵ��������Ρ�\n",a);
				else if(b==c)
					printf("�����������ɵ���������������Ϊ%d�ĵ��������Ρ�\n",b);
				else if(a==c)
					printf("�����������ɵ���������������Ϊ%d�ĵ��������Ρ�\n",a);
			}
			//ֱ�������� 
			else if(a*a+b*b==c*c)
				printf("�����������ɵ�����������%d,%dΪֱ�Ǳߵ�ֱ�������Ρ�\n",a,b);
			else if(b*b+c*c==a*a)
				printf("�����������ɵ�����������%d,%dΪֱ�Ǳߵ�ֱ�������Ρ�\n",c,b);
			else if(c*c+a*a==b*b)
				printf("�����������ɵ�����������%d,%dΪֱ�Ǳߵ�ֱ�������Ρ�\n",c,a);
				
			else
				printf("�������μȲ��ǵ��������Σ�Ҳ���ǵȱ������Σ�Ҳ����ֱ�������Ρ�\n");//����ͨ�������� 
		}
		else
		{
			printf("\a������������޷����������Ρ�\n");
		} 
	}
	else
	{
		printf("\a�����θ��߳�����С��0��\n") ; 
	}
}
int main()
{
	while(1)
	{
		int a=0,b=0,c=0;
		printf("�����������ε������ߣ�\n");
		if(scanf("%d%d%d",&a,&b,&c)==3)
		{
			isTriangle(a,b,c);
			while(getchar()!='\n');//��ջ��������Ա��´����� 
		}
		else
		{
			printf("\a��������������\n");
			while(getchar()!='\n');
		}
		printf("--------------------------------------\n");		
	}
	return 0;
}