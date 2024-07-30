#include <stdio.h>

//练习回调函数和函数指针数组 

void menu()
{
	printf("*********************\n");
	printf("*** 1.add   2.min ***\n");
	printf("*** 3.mul   4.div ***\n");
	printf("*** 0.exit       ****\n");
	printf("*********************\n");
}

int Add(int x, int y)
{
	return x+y;
}

int Min(int x, int y)
{
	return x-y;
}

int Mul(int x, int y)
{
	return x*y;
}

int Div(int x, int y)
{
	if(y!=0)
		return x/y;
	else 
	{
		printf("输入错误，除数不能为 '0' \n");
		return -1;	
	}

}

 calc(int input,int (*pf[])(int,int))
{
	int x=0,y=0;
	printf("请输入两个数:>");
	scanf(" %d %d",&x,&y);
	printf("%d\n\n",pf[input](x,y));
}
int main()
{
	int input=0;
	int (*pfArr[5])(int,int)={0,Add,Min,Mul,Div};
	do{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		if(input>0 && input <5) calc(input,pfArr); 
		else if(input == 0) printf("退出计算器\n");
		else printf("输入错误，请重试\n");
	}while(input);
	return 0;
}
