#include <stdio.h>
//����ˮ��һԪһƿ������ƿ�ǻ�һƿ��20Ԫ���Ժȼ�ƿ 

int conversion(int money,int bottle)
{
	if(money<1 && bottle<2)
	{
		return 0;
	}
	int totalBottle=0;
	while (money>=1)
	{
		money--;
		bottle++;
		totalBottle++; 
	}
	while(bottle>=2)
	{
		bottle-=2;
		money++;
	}
	return totalBottle+=conversion(money,bottle);
}
int main()
{
	int money=20;
	int bottle=0;
	printf("%d",conversion(money,bottle)); 
}
