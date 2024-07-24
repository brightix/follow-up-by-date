#include <stdio.h>


void isTriangle(const int a,const int b, const int c)
{
	if(a!=0 && b!=0 && c!=0)//判断边长合法性 
	{
		if(a<b+c && b<a+c && c<a+b)//三角形任意两边之和一定大于第三边
		{
			if(a==b||b==c||a==c)//判断三角形类型 
			{
				if(a==b && a==c)
					printf("该三边所构成的三角形是以边长为%d的等边三角形。\n",a); 
				else if(a==b)
					printf("该三边所构成的三角形是以腰长为%d的等腰三角形。\n",a);
				else if(b==c)
					printf("该三边所构成的三角形是以腰长为%d的等腰三角形。\n",b);
				else if(a==c)
					printf("该三边所构成的三角形是以腰长为%d的等腰三角形。\n",a);
			}
			//直角三角形 
			else if(a*a+b*b==c*c)
				printf("该三边所构成的三角形是以%d,%d为直角边的直角三角形。\n",a,b);
			else if(b*b+c*c==a*a)
				printf("该三边所构成的三角形是以%d,%d为直角边的直角三角形。\n",c,b);
			else if(c*c+a*a==b*b)
				printf("该三边所构成的三角形是以%d,%d为直角边的直角三角形。\n",c,a);
				
			else
				printf("该三角形既不是等腰三角形，也不是等边三角形，也不是直角三角形。\n");//最普通的三角形 
		}
		else
		{
			printf("\a您输入的三边无法构成三角形。\n");
		} 
	}
	else
	{
		printf("\a三角形各边长不能小于0。\n") ; 
	}
}
int main()
{
	while(1)
	{
		int a=0,b=0,c=0;
		printf("请输入三角形的三条边：\n");
		if(scanf("%d%d%d",&a,&b,&c)==3)
		{
			isTriangle(a,b,c);
			while(getchar()!='\n');//清空缓冲区，以便下次输入 
		}
		else
		{
			printf("\a输入有误！请重试\n");
			while(getchar()!='\n');
		}
		printf("--------------------------------------\n");		
	}
	return 0;
}
