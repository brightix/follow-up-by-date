#include<stdio.h>

int main(){
	int a=0,b=0;
	int i=1;
	while(scanf("%d%d",&a,&b))
	{
		/*
		for(i=a>b?a:b;i<100000;i++)//方法一 
		{
			if(i%a==0 && i%b==0)
			{
				printf("最小公倍数为%d\n",i);
				break;		
			}
		}*/	
		
		
		while((i*a)%b!=0)//方法二  速度更快 
		{
			i++;
		}
		printf("最小公倍数为%d\n",i*a);
		while(getchar()!='\n');//清空缓冲区 
	}
	return 0;
}
